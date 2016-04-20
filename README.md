# algorithm-benchmarking-analysis
This repository contains all of the implementations of a series of algorithms
for solving a set of computer science-theoretical problems. It will also
contain scripts used for statistical analysis of the benchmarking data.

[Project site](http://kraemerd17.github.io/algorithm-benchmarking-analysis) (under construction)


# Formal Problems

## Sorting a list

* Insertion sort
* Merge sort

## Searching a list

* Linear search
* Binary search

## Theory

| Algorithm | List size | Complexity |
|:----------|:----------|:-----------|
| Binary search | n | O(log n) |
| Linear search | n | O(n) |
| Merge sort | n | O(n log n) |
| Insertion sort | n | O(n^2) |

# Implementations

## Implementation invariants

* Searching and sorting arrays of doubles of known length

## Implementation paradigms

* Recursive (tail when available)
* Iterative 

## Languages

* C
* Scheme
* Python

# Experiments

## Linear models

* Run time is the response variable and input size is the explanatory variable
* So, we'll observe a number of CPU wall times for a given input size and fit this with a linear model
