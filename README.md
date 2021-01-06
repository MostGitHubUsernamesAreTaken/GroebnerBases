# GroebnerBases
[![Build Status](https://api.travis-ci.org/MostGitHubUsernamesAreTaken/GroebnerBases.svg?branch=master)](https://travis-ci.org/MostGitHubUsernamesAreTaken/GroebnerBases)

(Code is a work in progress.)

This is a simple command line calculator of Groebner bases.  A multinomial class is built on top of a computer algebra system (here GiNaC).  That choice is something of an extravagance; one could also just write a hack.  However the overhead is in non-critical parts of the Groebner basis algorithms so there is no significant performance price.  The benefit is that the algorithms for Groebner bases can be implemented in an elegant way.  Additionally I was interested in a template library type implementation that would allow the specific implementation of multinomials to be changed easily.  By starting with a multinomial class some work in that direction is completed.

Two Groebner basis algorithms are implemented; Buchberger's algorithm and F4.
