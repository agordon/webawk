WebAWK - AWK in Javascript
=================

This is an adaptation of the [AWK](http://en.wikipedia.org/wiki/AWK) programming language
running entirely in Javascript, on the client-side web-browse (or on node.js).

*NOTE*
This is not a re-implementation of AWK in Javascript.
The C source code of [Busybox AWK](http://www.busybox.net/) was compiled (slightly modified) using [emscripten](http://emscripten.org/) (a LLVM-to-Javascript compiler).


Using WebAWK
------------

Online demo: http://agordon.github.com/webawk/
Interactive AWK demo (requires a recent web-browser): http://agordon.github.com/webawk/awk_web_worker.html

Try locally:

    # download the code.
    $ git clone git://github.com/agordon/webawk.git
    $ cd webawk

    # use the supplied pre-built javascripts, to save time and effort.
    $ make prebuilt

    # test the node.js version
    # (need to have "node" installed, obviously)
    $ make node-test

    # test the web version
    # (this will print the URL of the file you'll need to open in your browser)
    $ make web-test

    # or build the javascripts, by compiling the C code.
    # see compilation instructions below.
    $ make node
    $ make web

    # To debug / add features, compile for a native binary
    $ make bin
    $ make bin-test


Re-building the Javascript code
-------------------------------

To rebuild the javascript code, you'll need the `clang` and the `emscripten` compilers.
Follow the ([emscripten Tutorial](https://github.com/kripken/emscripten/wiki/Tutorial) for installation and testing instructions.

**node.js version**

* To compile the *node.js version*, run ```make node``` .
* The *node.js version* is configured to start immediately (i.e. calling AWK's `main()` function).
* The fcompiled output file is `awk_node.js`, and using it with node should be equivalent to running `awk` on the command line (note:  equivalent to the old oawk, not GNU awk).
* Try the following (which are equivalent to `make node-test`):

```
       $ node awk_node.js 'BEGIN { print "Hello Node Awk World" ; exit }'
       vs.
       $ awk 'BEGIN { print "Hello Awk World" ; exit }'

	or

       $ node awk_node.js -f tests/my_program.awk tests/my_input.txt
       vs
       $ awk -f tests/my_program.awk tests/my_input.txt

       # Technical note:
       # the node version doesn't read the input files from 'tests' -
       # the files are embedded in the javascript during compilation
       # (so don't expect to change them and see the results)

```


**web version**

* To compile the *web version*, run ```make web``` .
* The compiled output file is `website/awk_web.js`. It contains the emscripten'd AWK code, wrapped in a single javascript function `run_web_awk()` .
* Load the file `websize/awk_web.js` in your web-browser to run sample AWK programs.
* The *web version* is configured with additional wrappers, and a friendly javascript function that runs awk on a given input. The source code for the wrappers is in `js_emsc` sub-directory.
* See `tests/web_test.js` for an example of calling this function.


**Compilation Warnings**

Some warnings and error messages are expected when compiling with **emscripten**.

Warnings similar to these can be ignored:

```
In file included from heirloom_emsc/libuxre/onefile.c:33:
heirloom_emsc/libuxre/bracket.c:801:14: warning: array index of '1' indexes past the end of an array (that contains 1 element)
      [-Warray-bounds]
                mcbuf.wc = mcbuf.cep->weight[1];
                           ^                 ~
heirloom_emsc/libuxre/colldata.h:163:2: note: array 'weight' declared here
        wuchar_type     weight[COLL_WEIGHTS_MAX];
        ^
In file included from heirloom_emsc/libuxre/onefile.c:37:
heirloom_emsc/libuxre/regcomp.c:55:23: warning: '&&' within '||' [-Wlogical-op-parentheses]
        if (ep->re_nsub != 0 && (flags & (REG_NOSUB | REG_ONESUB)) == 0
            ~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
heirloom_emsc/libuxre/regcomp.c:55:23: note: place parentheses around the '&&' expression to silence this warning
        if (ep->re_nsub != 0 && (flags & (REG_NOSUB | REG_ONESUB)) == 0
                             ^
```

Also, the following **unresolved symbols** are expected:

```
Warning: Unresolved symbol: _llvm_va_start
Warning: Unresolved symbol: _llvm_dbg_declare
Warning: Unresolved symbol: _llvm_expect_i32
```

However, if you get compilation errors, or other unresolved symbols - that's a likely problem that might prevent AWK from functioning.


Compiling the AWK binary
------------------------

* To compile the *binary version*, run ```make bin``` (you'll need the `clang` compiler).
* The compiled output file is `awk_bin`.
* This file can be easily debugged with `gdb` (or similar debuggers).


BusyBox AWK
-----------

This awk implementation is based (=copied) from Busybox's AWK implementation, written by Dmitry Zakharov <dmit@crp.bank.gov.ua>. It also uses many of the `libbb` functions.

Website: http://www.busybox.net/

The code is based on Busybox version 1.20.2 .

To see the changes, run:

```
$ git clone git://github.com/agordon/webawk.git
$ wget http://www.busybox.net/downloads/busybox-1.20.2.tar.bz2
$ tar -xjf busybox-1.20.2.tar.bz2
$ diff -rup busybox-1.20.2/ weback/busybox
```

NEWLIB
------

This implementation uses the Posix Regular Expression code and the `getopt()` functions from RedHat's newlib.

Website: http://sourceware.org/newlib/

The code is based on Newlib 1.20.0 .

To see the changes, run:

```
$ git clone git://github.com/agordon/webawk.git
$ wget ftp://sources.redhat.com/pub/newlib/newlib-1.20.0.tar.gz
$ tar -xzf newline-1.20.0.tar.gz
$ diff -rup newlib-1.20.0/newlib webawk/newlib
```

HACKING
-------

See the `HACKING` file for more details.


Contact
-------

email: gordon at cshl dot edu
source: https://github.com/agordon/webawk.git


License
-------

* The newlib `getopt` code is public domain.
* The newlib `Regex` code is BSD.
* The busybox code is GPLv2.
* All other files are BSD.
