ms_interview_100
================
[![Build Status](https://travis-ci.org/alvas/ms_interview_100.svg?branch=master)](https://travis-ci.org/alvas/ms_interview_100)
[![Coverage Status](https://coveralls.io/repos/alvas/ms_interview_100/badge.svg?branch=master&service=github)](https://coveralls.io/github/alvas/ms_interview_100?branch=master)

This is the code implementation for some interview questions, including leetcode

To compile the target in the make file:
make *target_name*, for example: `make Select`

leetcode solutions in leetcode folder are assigned a number according to the question number on leetcode website.
Build leetcode solution by specifying its number:
`make 1`, is the same as `make TwoSum`

In order to create configure script, use the command touch configure.ac and then use autoconf to generate an empty configure script file.
