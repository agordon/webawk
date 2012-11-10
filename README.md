WebAWK - AWK in Javascript
=================

This is an adaptation of the [AWK](http://en.wikipedia.org/wiki/AWK) programming language
running entirely in Javascript, on the client-side web-browse (or on node.js).

*NOTE*
This is not a re-implementation of AWK in Javascript.
The C source code of *oawk* ([The 'old' one-true AWK](http://en.wikipedia.org/wiki/AWK#Versions_and_implementations))
from the [heirloom project](http://heirloom.sourceforge.net/tools.html) was compiled (unmodified) using [emscripten](http://emscripten.org/) (a LLVM-to-Javascript compiler).


Using WebAWK
------------

Online demo: **TODO: add URL**

Try locally:

    # download the code.
    $ git clone git://github.com/agordon/webawk.git
    $ cd webawk

    # use the supplied pre-built javascripts, to save time and effort.
    $ make prebuilt

    # or build the javascripts, by compiling the C code.
    # see compilation instructions below.
    $ make node
    $ make web

    # run the Javascript/AWK using "node" (need to have "node" installed, obviously)
    $ make node-test

    # or load it in your browser.
    # (this will print the URL of the file you'll need to open in your browser)
    $ make web-test



Re-building the Javascript code
-------------------------------

To rebuild the javascript code, you'll need the `clang` and the `emscripten` compilers.
Follow the ([emscripten Tutorial](https://github.com/kripken/emscripten/wiki/Tutorial) for installation and testing instructions.

**node.js version**

* To compile the *node.js version*, run ```make node``` .
* The *node.js version* is configured to start immediately (i.e. calling AWK's `main()` function).
* The fcompiled output file is `awk_node.js`, and using it with node should be equivalent to running `awk` on the command line (note:  equivalent to the old oawk, not GNU awk).
* Due to node.js's FileSystem routines, you can't load files (with `-f`) or read input files without adding more javascript code.
* Try:

```
       $ node awk_node.js 'BEGIN { print "Hello Node Awk World" ; exit }'
       vs.
       $ awk 'BEGIN { print "Hello Awk World" ; exit }'
```


**web version**

* To compile the *web version*, run ```make web``` .
* The compiled output file is `website/awk_web.js`. It contains the emscripten'd AWK code, wrapped in a single javascript function `run_web_awk()` .
* Load the file `websize/awk_web.js` in your web-browser to run sample AWK programs.
* The *web version* is configured with additional wrappers, and a friendly javascript function that runs awk on a given input. The source code for the wrappers is in `js_emsc` sub-directory.
* To call awk from Javascript, use the following Javascript code:

```
	//The AWK program
	var awk_source = '$1 > 2 { print $2}';

	//The input file for the AWK program
	var sample_input = "1 A\n2 B\n3 C\n";

	//Run AWK
	var awk = run_web_awk( awk_source, sample_input ) ;

	console.log("exit code = " + awk.exit_code );
	console.log("awk output = " + awk.stdout );
	console.log("awk errors = " + awk.stderr );
```


Heirloom awk
------------

Website: http://heirloom.sourceforge.net/tools.html

The `heirloom_emsc` sub-directory contains the `oawk` and `libuxre` (unmodified) from the heirloom source code (CVS version: revision 1.192,  date: 2010/10/09 21:19:23 ).

To get the entire heirloom source code, run this:

    # Fetch the latest heirloom code
    cvs -d:pserver:anonymous@heirloom.cvs.sourceforge.net:/cvsroot/heirloom login
    cvs -d:pserver:anonymous@heirloom.cvs.sourceforge.net:/cvsroot/heirloom co -P heirloom



Contact
-------

email: gordon at cshl dot edu
source: https://github.com/agordon/webawk.git



License
-------

* The `libuxre` heirloom library is LGPL 2.1
* The `oawk` heirloom program is BSD.
* All other files are BSD.
