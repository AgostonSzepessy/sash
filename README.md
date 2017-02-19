# Sash
Sash is a basic Unix shell written in C. The purpose of this project is to help me learn how Unix shells work.

# Requirements
You will need the following installed on your computer:
* [Git](https://git-scm.com/)
* [CMake](https://cmake.org/)
* A Unix environment

# Building
* `git clone https://github.com/AgostonSzepessy/sash.git`
* `mkdir sash_build`
* `cd sash_build`
* `cmake ../sash`
* `make -j3`

# Running
The binaries are placed into `sash_build/bin`. To run `sash`:

```sash_build/bin/sash```

To run the tests:
* `cd sash_build`
* `ctest`

# Useful links
* [POSIX Shell Command Language Specification](http://pubs.opengroup.org/onlinepubs/007904875/utilities/xcu_chap02.html)
* [Check Unit Testing Framework for C](https://libcheck.github.io/check/)
