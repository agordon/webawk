
EMCC=emcc
# if 'emcc' (the emscripten compiler) is not in your $PATH,
# set the full path here:
#EMCC=~/sources/emscripten/emcc

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
		busybox/libbb/xatonum.c \
		busybox/c_stubs/missing_functions.c


BUSYBOX_INCLUDE_PATH=-Ibusybox/include

OPT_FLAGS=-O2

JS_FLAGS=-s WARN_ON_UNDEFINED_SYMBOLS=1 \
	-s CATCH_EXIT_CODE=1

PRE_JS_SRC=js_emsc/pre_AWK.js
POST_JS_SRC=js_emsc/post_AWK.js

.PHONY: all
all: bb
oo-all:
	@echo
	@echo "WebAWK - AWK in Javascript"
	@echo "  https://github.com/agordon/webawk.git"
	@echo ""
	@echo "  See README.md for more details"
	@echo ""
	@echo "Possible targets:"
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

website/awk_web.js: check_emcc $(OAWK_SRC) $(LIBUXRE_SRC) $(STUB_SRC) $(PRE_JS_SRC) $(POST_JS_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(INCLUDE_PATH) \
		$(OAWK_SRC) \
		$(LIBUXRE_SRC) \
		$(STUB_SRC) \
		--pre-js $(PRE_JS_SRC) \
		--post-js $(POST_JS_SRC) \
		-o $@

.PHONY: web-test
web-test:
	@echo
	@echo "To test on in your web browser, load the following file:"
	@echo "  file://$(PWD)/website/awk_web.html"
	@echo
	@echo

.PHONY: node
node: awk_node.js

awk_node.js: check_emcc $(BUSYBOX_AWK_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(BUSYBOX_INCLUDE_PATH) \
		$(BUSYBOX_AWK_SRC) \
		-o $@

cl: $(BUSYBOX_AWK_SRC)
	clang -O0 -g \
		$(BUSYBOX_INCLUDE_PATH) \
		$(BUSYBOX_AWK_SRC) \
		-o $@


.PHONY: node-test
node-test:
	@echo
	@echo "Running Javascript/AWK parser using node ."
	@echo "  You should see an \"Hello World\" message below:"
	@echo
	node awk_node.js 'BEGIN { print "Hello from Javascript/AWK" ; exit }'
	@echo
	@echo


.PHONY: clean
clean: clean-node clean-web


.PHONY: clean-node
clean-node:
	rm -f awk_node.js

.PHONY: clean-web
clean-web:
	rm -f website/awk_web.js



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
