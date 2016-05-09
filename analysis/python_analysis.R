pybs <- read.csv("~/mat336/projects/algorithm-benchmarking-analysis/python_code/search/bsi_python.csv")
pyls <- read.csv("~/mat336/projects/algorithm-benchmarking-analysis/python_code/search/lsi_python.csv")

plot(time~input, data=pybs)
plot(time~input, data=pyls)
abline(pylslm$coefficients)
pylslm <- lm(time~input, data=pyls)

pyls$mean_times <- sapply(pyls$input, function(x) {mean(pyls$time[pyls$input == x])} )

plot(mean_times~input, data=pyls)
mean_model <- lm(mean_times~input, data=pyls)
abline(mean_model$coefficients)

pyls$max_times <- sapply(pyls$input, function(x) {max(pyls$time[pyls$input == x])} )
plot(max_times~input, data=pyls)
max_model <- lm(max_times~input, data=pyls)
abline(max_model$coefficients)
