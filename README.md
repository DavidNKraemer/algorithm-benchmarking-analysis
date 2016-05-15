# algorithm-benchmarking-analysis
This repository contains all of the implementations of a series of algorithms
for solving a set of computer science-theoretical problems. It will also
contain scripts used for statistical analysis of the benchmarking data.

# TODOs for Analysis

* [Presentation](https://www.overleaf.com/5137733pskbcz)
* [Paper](https://www.overleaf.com/4636137dmzkwk)

* Fit a simple linear model on the data and compare it to the theorized model
    * Look at model diagnostics
    * Prediction and confidence intervals
    * Compare linear models for the max and mean runtime (this approximates 
      average case and Big Oh coefficients).
* Do paired testing on:
    * Recursion vs iteration on C
    * Implementation differences between languages for a fixed algorithm

## Research questions

* Are iterative algorithms demonstrably faster than recursive algorithms?
* Is C faster than Scheme faster than Python?
* What is the tradeoff between complex algorithms and faster results?


# Formal Problems

## Sorting a list

* Insertion sort
* Merge sort

## Searching a list

* Linear search
* Binary search

## Theory

| Algorithm | List size | Complexity | C | Python | Scheme |
|:----------|:----------|:-----------|:--|:-------|:-------|
| Binary search | n | O(log n) | IR | IR | |
| Linear search | n | O(n) | IR | IR | |
| Merge sort | n | O(n log n) | IR | | |
| Insertion sort | n | O(n^2) | IR | | |

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
