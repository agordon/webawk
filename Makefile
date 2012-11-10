
EMCC=emcc

# if 'emcc' (the emscripten compiler) is not in your $PATH,
# set the full path here:
#EMCC=~/sources/emscripten/emcc

OAWK_SRC=heirloom_emsc/oawk/lib.c \
	heirloom_emsc/oawk/parse.c \
	heirloom_emsc/oawk/awk.g.c \
	heirloom_emsc/oawk/run.c \
	heirloom_emsc/oawk/main.c \
	heirloom_emsc/oawk/token.c \
	heirloom_emsc/oawk/version.c \
	heirloom_emsc/oawk/proctab.c \
	heirloom_emsc/oawk/b.c \
	heirloom_emsc/oawk/awk.lx.c \
	heirloom_emsc/oawk/freeze.c \
	heirloom_emsc/oawk/tran.c

LIBUXRE_SRC=heirloom_emsc/libuxre/onefile.c \
	    heirloom_emsc/libuxre/regerror.c \
	    heirloom_emsc/libuxre/regfree.c \

STUB_SRC=c_emsc/stubs.c

INCLUDE_PATH=-Iheirloom_emsc/libuxre


# -O2 currently doesn't work (the "undefined is not a function" error)
#OPT_FLAGS=-O2 --closure 0

OPT_FLAGS=-O1 --closure 0

JS_FLAGS=-s WARN_ON_UNDEFINED_SYMBOLS=1 \
	-s CATCH_EXIT_CODE=1

PRE_JS_SRC=js_emsc/pre_AWK.js
POST_JS_SRC=js_emsc/post_AWK.js

.PHONY: all
all:
	@echo "what?"


.PHONY: web
web: website/awk_web.js

website/awk_web.js: $(OAWK_SRC) $(LIBUXRE_SRC) $(STUB_SRC) $(PRE_JS_SRC) $(POST_JS_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(INCLUDE_PATH) \
		$(OAWK_SRC) \
		$(LIBUXRE_SRC) \
		$(STUB_SRC) \
		--pre-js $(PRE_JS_SRC) \
		--post-js $(POST_JS_SRC) \
		-o $@

.PHONY: web-test
web-test: web
	@echo
	@echo "To test on in your web browser, load the following file:"
	@echo "  file://$(PWD)/website/awk_web.html"
	@echo
	@echo

.PHONY: node
node: awk_node.js

awk_node.js: $(OAWK_SRC) $(LIBUXRE_SRC) $(STUB_SRC)
	$(EMCC) $(OPT_FLAGS) $(JS_FLAGS) \
		$(INCLUDE_PATH) \
		$(OAWK_SRC) \
		$(LIBUXRE_SRC) \
		$(STUB_SRC) \
		-o $@

.PHONY: node-test
node-test: node
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

