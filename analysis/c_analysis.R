require(fastR)

# The actual data
c_search <- read.csv("../data/output_data/c_search.csv")
c_sort <- read.csv("../data/output_data/c_sort.csv")
c_search <- c_search[c_search$time > 0,]
c_sort <- c_sort[c_sort$time > 0,]
# First visual inspection
xyplot(time~input|algorithm, data=c_search)
xyplot(time~input|algorithm, data=c_sort)

nlogn <- function(n) {
  return(n * log(n, base = 2))
}

insertion_iterative <- c_sort[c_sort["algorithm"] == "insertion_iterative",]
insertion_recursive <- c_sort[c_sort["algorithm"] == "insertion_recursive",]
merge_iterative <- c_sort[c_sort["algorithm"] == "merge_iterative",]
merge_recursive <- c_sort[c_sort["algorithm"] == "merge_recursive",]
linear_iterative <- c_search[c_search["algorithm"] == "linear_iterative",]
linear_recursive <- c_search[c_search["algorithm"] == "linear_recursive",]
binary_iterative <- c_search[c_search["algorithm"] == "binary_iterative",]
binary_recursive <- c_search[c_search["algorithm"] == "binary_recursive",]

# Fitting linear models

# Iterative insertion sort
insertion.iter.simple_lm           <- lm(time ~ input,      data=insertion_iterative)
insertion.iter.theoretical_lm      <- lm(time ~ I(input^2), data=insertion_iterative)
insertion.iter.simple_summary      <- summary(insertion.iter.simple_lm)
insertion.iter.theoretical_summary <- summary(insertion.iter.theoretical_lm)
# Recursive insertion sort
insertion.rec.simple_lm            <- lm(time~input,        data=insertion_recursive)
insertion.rec.theoretical_lm       <- lm(time~I(input^2),   data=insertion_recursive)
insertion.rec.simple_summary       <- summary(insertion.rec.simple_lm)
insertion.rec.theoretical_summary  <- summary(insertion.rec.theoretical_lm)
# Iterative merge sort
merge.iter.simple_lm <- lm(time~input, data=merge_iterative)
merge.iter.theoretical_lm <- lm(time~I(nlogn(input)), data=merge_iterative)
merge.iter.simple_summary <- summary(merge.iter.simple_lm)
merge.iter.theoretical_summary <- summary(merge.iter.theoretical_lm)
# Recursive merge sort
merge.rec.simple_lm <- lm(time~input, data=merge_recursive)
merge.rec.theoretical_lm <- lm(time~I(nlogn(input)), data=merge_recursive)
merge.rec.simple_summary <- summary(merge.rec.simple_lm)
merge.rec.theoretical_summary <- summary(merge.rec.theoretical_lm)

# Iterative linear search
linear.iter.simple_lm <- lm(time~input, data=linear_iterative)
linear.iter.theoretical_lm <- lm(time~input, data=linear_iterative)
linear.iter.simple_lm <- summary(linear.iter.simple_lm)
linear.iter.theoretical_summary <- summary(linear.iter.theoretical_lm)
# Recursive linear search
linear.rec.simple_lm <- lm(time~input, data=linear_recursive)
linear.rec.theoretical_lm <- lm(time~input, data=linear_recursive)
linear.rec.simple_lm <- summary(linear.rec.simple_lm)
linear.rec.theoretical_summary <- summary(linear.rec.theoretical_lm)
# Iterative binary search
binary.iter.simple_lm <- lm(time~input, data=binary_iterative)
binary.iter.theoretical_lm <- lm(time~I(log(input, base=2)), data=binary_iterative)
binary.iter.simple_summary <- summary(binary.iter.simple_lm)
binary.iter.theoretical_summary <- summary(binary.iter.theoretical_lm)
# Recursive binary search
binary.rec.simple_lm <- lm(time~input, data=binary_recursive)
binary.rec.theoretical_lm <- lm(time~I(log(input, base=2)), data=binary_recursive)
binary.rec.simple_summary <- summary(binary.rec.simple_lm)
binary.rec.theoretical_summary <- summary(binary.rec.theoretical_lm)

# Recursive vs Iterative paired t-tests
insertion.paired <- t.test(insertion_iterative$time, insertion_recursive$time, paired=TRUE)
merge.paired     <- t.test(merge_iterative$time, merge_recursive$time, paired=TRUE)
linear.paired    <- t.test(linear_iterative$time, linear_recursive$time, paired=TRUE)
binary.paired    <- t.test(binary_iterative$time, binary_recursive$time, paired=TRUE)

# Sorting paired tests
insertion_vs_merge.iter <-t.test(insertion_iterative$time, merge_iterative$time, paired=TRUE)
insertion_vs_merge.rec  <-t.test(insertion_recursive$time, merge_recursive$time, paired=TRUE)

linear_vs_binary.iter <-t.test(linear_iterative$time, binary_iterative$time, paired=TRUE)
linear_vs_binary.rec  <-t.test(linear_recursive$time, binary_recursive$time, paired=TRUE)
