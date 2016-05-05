sort_data <- read.csv("~/mat336/projects/algorithm-benchmarking-analysis/data/output_data/c_sort.csv")
search_data <- read.csv("~/mat336/projects/algorithm-benchmarking-analysis/data/output_data/c_search.csv")

sort_data <- sort_data[sort_data$time > 0,]
require(lattice)
scatterplot(time~input|algorithm, data=sort_data)

insert_rec <- sort_data[sort_data$algorithm == "insertion_recursive",]
plot(time~input, data=insert_rec)

insert_rec.simple_lm <- lm(time~input, data=insert_rec)
insert_rec.theorized_lm <- lm(sqrt(time)~input, data=insert_rec)

insert_iter <- sort_data[sort_data$algorithm == "insertion_iterative",]
plot(sqrt(time)~input, data=insert_iter)
abline(insert_iter.theorized_lm)

insert_iter.simple_lm <- lm(time~input, data=insert_iter)
insert_iter.theorized_lm <- lm(sqrt(time)~input, data=insert_iter)

merge_iter <- sort_data[sort_data$algorithm == "merge_iterative",]
merge_iter.simple_lm <- lm(time~input, data=merge_iter)
merge_iter.theorized_lm <- lm(sqrt(time)~input, data=merge_iter)
plot(time~input, data=merge_iter)
abline(merge_iter.theorized_lm)


