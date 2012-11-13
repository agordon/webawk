/*
   This is a driver for testing the AWK javascript generated for the web
   (as opposed to the one generated for node.js)

   It is assumed the generated javascript is concatenated above this script,
   and that it exposes a single javascript function: run_web_awk().

   See "make web-test" .
 */

var test1_program = 'BEGIN { print "Hello Busybox/AWK/Javascript World" } $$2 ~ /2/ { print $$1 }';
var test1_input = "1 A\n2 B\n3 C\n";

var r = run_web_awk(test1_program, test1_input);

console.log("test1 exit code: " + r.exit_code);

