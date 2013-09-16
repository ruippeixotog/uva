# Solutions to [UVa Online Judge][1] problems

This repository contains solutions to UVa Online Judge problems, available at [http://uva.onlinejudge.org/][1]. These solutions are provided "as is". I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and id of the problem you want to compile (see section "Problems Solved" for the list of possible ids):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `100` with the id of the desired problem:

    $ ./100

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem id is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete and/or aren't efficient enough.

### Problem Set Volumes

#### Volume 1

* ✓ [The 3n + 1 problem][100] (`100`)

[1]: http://uva.onlinejudge.org/
[100]: http://uva.onlinejudge.org/external/1/100.html