
EMCC=emcc
# if 'emcc' (the emscripten compiler) is not in your $PATH,
# set the full path here:
#EMCC=~/sources/emscripten/emcc

NEWLIB_SRC=newlib/libc/posix/regerror.c \
	newlib/libc/posix/regfree.c \
	newlib/libc/posix/regcomp.c \
	newlib/libc/posix/collcmp.c \
	newlib/libc/posix/collate.c \
	newlib/libc/posix/regexec.c \
	newlib/libc/stdlib/getopt.c


BUSYBOX_AWK_SRC=busybox/editors/awk.c \
		busybox/libbb/wfopen_input.c \
		busybox/libbb/skip_whitespace.c \
		busybox/libbb/llist.c \
		busybox/libbb/wfopen.c \
		busybox/libbb/xfuncs_printf.c \
		busybox/libbb/xfuncs.c \
		busybox/libbb/messages.c \
		busybox/libbb/verror_msg.c \
		busybox/libbb/process_escape_sequence.c \
		busybox/libbb/perror_msg.c \
		busybox/libbb/read.c \
		busybox/libbb/xfunc_die.c \
		busybox/libbb/full_write.c \
		busybox/libbb/copyfd.c \
		busybox/libbb/safe_write.c \
		busybox/libbb/platform.c \
		busybox/libbb/getopt32.c \
		busybox/libbb/xregcomp.c \
		busybox/libbb/xatonum.c \
		busybox/c_stubs/missing_functions.c

BUSYBOX_INCLUDE_PATH=-Ibusybox/include -Inewlib/libc/posix -Inewlib/libc/stdlib

#OPT_FLAGS=-O2 --closure 1 --minify 1
OPT_FLAGS=-O0

JS_FLAGS=-s WARN_ON_UNDEFINED_SYMBOLS=1 \
	-s CATCH_EXIT_CODE=1

PRE_JS_SRC=js_emsc/pre_AWK.js
POST_JS_SRC=js_emsc/post_AWK.js

.PHONY: all
all:
oo-all:
	@echo
	@echo "WebAWK - AWK in Javascript"
	@echo "  https://github.com/agordon/webawk.git"
	@echo ""
	@echo "  See README.md for more details"
	@echo ""
	@echo "Possible targets:"
	@echo "   make bin        - Compile native binary using CLANG for debugging (awk_bin)"
	@echo "   make bin-test   - test the binary version"
	@echo "   make node       - Compile the node version (awk_node.js)"
	@echo "   make node-test  - test the AWK node version"
	@echo "   make web        - Compile the web version (website/awk_web.js)"
	@echo "   make web-test   - Print the URL to test the web version"
	@echo ""
	@echo "   make prebuilt   - If you don't have llvm/clang/emscripten compilers"
	@echo "                       installed, use the pre-built javascript versions."
	@echo "                       run this target if you want to experiment with WebAWK"
	@echo "                       without compiling."
	@echo "   make clean      - delete the compiled javascript files."
	@echo ""
	@echo ""

.PHONY: check_emcc
check_emcc:
	@(if ! which "$(EMCC)" > /dev/null ; then \
	  echo "" >&2 ; \
	  echo "Error: can't find EMCC compiler (looking for '$(EMCC)')." >&2 ; \
	  echo "" >&2 ; \
	  echo "If you have EMCC installed, please add it to your PATH," >&2 ; \
	  echo "  or change the 'EMCC=' directive in this Makefile." >&2 ; \
	  echo "" >&2 ; \
	  echo "If you don't have EMCC installed, you can run 'make prebuilt'" >&2 ; \
	  echo "  to use the pre-built javascript versions." >&2 ; \
	  exit 1 ; \
	  fi )


.PHONY: web
web: website/awk_web.js

website/awk_web.js: $(BUSYBOX_AWK_SRC) $(NEWLIB_SRC) $(PRE_JS_SRC) $(POST_JS_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(BUSYBOX_INCLUDE_PATH) \
		-DWEBAWK_CALLBACK_CUSTOM \
		$(BUSYBOX_AWK_SRC) \
		$(NEWLIB_SRC) \
		--pre-js $(PRE_JS_SRC) \
		--post-js $(POST_JS_SRC) \
		-o $@

# Undocumented target:
#  create a Javascript+HTML stub for direct loading,
#  skipping the custom pre/post javascripts.
#  try this if you suspect a bug in the pre/post files.
test.html: check_emcc $(BUSYBOX_AWK_SRC) $(NEWLIB_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(BUSYBOX_INCLUDE_PATH) \
		$(BUSYBOX_AWK_SRC) \
		$(NEWLIB_SRC) \
		-o $@

.PHONY: web-test
web-test: website/awk_web.js tests/web_test.js
	@cat website/awk_web.js tests/web_test.js > tmp_web_test.js
	@echo
	@echo "Simulating a web-browser call to 'run_web_awk()':"
	@echo
	node tmp_web_test.js
	@echo
	@echo
	@echo
	@echo "To test on in your web browser, load the following file:"
	@echo "  file://$(PWD)/website/awk_web.html"
	@echo
	@echo
	@rm -f tmp_web_test.js

.PHONY: node
node: awk_node.js

# The node target embeds the two test input files
# in the jvascript (there's no easy filesystem access from the node script)
awk_node.js: check_emcc $(BUSYBOX_AWK_SRC) $(NEWLIB_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		-DWEBAWK_CALLBACK_CONSOLE \
		$(BUSYBOX_INCLUDE_PATH) \
		$(BUSYBOX_AWK_SRC) \
		$(NEWLIB_SRC) \
		--embed-file tests/my_program.awk \
		--embed-file tests/my_input.txt \
		-o $@

## Important node about the node test:
##  The AWK program will NOT read the actual input files (e.g. "tests/my_program.awk").
##  It will read the previously embedded files, from the Javascript.
##  (see the --embed-file command in the compilation stage)
.PHONY: node-test
node-test:
	@echo
	@echo "Running Javascript/AWK parser using node ."
	@echo "  You should see an \"Hello World\" message below:"
	@echo
	node awk_node.js 'BEGIN { print "Hello from Javascript/AWK" ; exit }'
	@echo
	@echo Second test: reading from input file
	@echo
	node awk_node.js -f tests/my_program.awk tests/my_input.txt
	@echo
	@echo
	@echo


.PHONY: bin
bin: awk_bin

awk_bin: $(BUSYBOX_AWK_SRC) $(NEWLIB_SRC)
	clang -O0 -g \
		$(BUSYBOX_INCLUDE_PATH) \
		$(BUSYBOX_AWK_SRC) \
		$(NEWLIB_SRC) \
		-o $@

# Quick and dirty test to check the native-compiled busybox awk
.PHONY: bin-test
bin-test: awk_bin
	@echo
	@echo "Running AWK binary."
	@echo "  You should see an \"Hello World\" message below:"
	@echo
	printf "1 A\n2 B\n3 C\n" | ./awk_bin 'BEGIN { print "Hello Busybox/AWK/Clang World" } $$1 ~ /2/ { print $$2 }'
	@echo
	@echo Second test: reading from input file
	@echo
	./awk_bin -f tests/my_program.awk tests/my_input.txt
	@echo
	@echo
	@echo



.PHONY: clean
clean: clean-node clean-web clean-bin


.PHONY: clean-node
clean-node:
	rm -f awk_node.js

.PHONY: clean-web
clean-web:
	rm -f website/awk_web.js

.PHONY: clean-bin
clean-bin:
	rm -f awk_bin



.PHONY: prebuilt
prebuilt:
	@echo "copying pre-built javascript files..."
	@gunzip -dc prebuilt/awk_node.js.gz > awk_node.js
	@gunzip -dc prebuilt/awk_web.js.gz > website/awk_web.js
	@echo "Done."
	@echo
	@echo "Try testing the prebuilt files with:"
	@echo "  make node-test"
	@echo "  make web-test"
	@echo ""


.PHONY: buildpre
buildpre: node web
	@echo "storing new pre-built javascript files..."
	@gzip -c awk_node.js > prebuilt/awk_node.js.gz
	@gzip -c website/awk_web.js > prebuilt/awk_web.js.gz
