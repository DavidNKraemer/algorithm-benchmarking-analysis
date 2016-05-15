#Linear models and transformation
binary.model<-lm(V1~V2,data=scheme_binary_search)
summary(binary.model)
binary.model.log<-lm(V1~I(log2(V2)),data=scheme_binary_search)
summary(binary.model.log)

linear.model<-lm(V1~V2,data=scheme_linear_search)
summary(linear.model)

insertion.model<-lm(V1~I(V2^2),data=scheme_insertion_sort)
summary(insertion.model)


nlogn <- function(n) {
  return(n * log(n, base=2))
}

merge.model<-lm(V1~V2,data=scheme_merge_sort)
summary(merge.model)
merge.model.log<-lm(V1~I(nlogn(V2)),data=scheme_merge_sort)
summary(merge.model.log)







#Paired t tests

##Different alg in scheme
scheme.search.diff<-scheme_linear_search$V1-scheme_binary_search$V1
scheme.sort.diff<-scheme_insertion_sort$V1-scheme_merge_sort$V1

######################binary is faster than linear
t.test(search.diff) 

#####################merge is faster than insertion
t.test(sort.diff) 







##C vs Scheme (recursive)
c.insertion.recursive<-c_sort[which(c_sort$algorithm == "insertion_recursive"),]
c.insertion.recursive<-c.insertion.recursive[c(1:490),]

c.linear.recursive<-c_search[which(c_search$algorithm == "linear_recursive"),]
c.linear.recursive<-c.linear.recursive[c(1:490),]

c.binary.recursive<-c_search[which(c_search$algorithm == "binary_recursive"),]
c.binary.recursive<-c.binary.recursive[c(1:490),]

c.merge.recursive<-c_sort[which(c_sort$algorithm == "merge_recursive"),]
c.merge.recursive<-c.merge.recursive[c(1:490),]

#####################C is faster in all cases
###insertion sort
t.test(c.insertion.recursive$time,scheme_insertion_sort$V1,paired=T)
###merge sort
t.test(c.merge.recursive$time,scheme_merge_sort$V1,paired=T)
###binary search
t.test(c.binary.recursive$time,scheme_binary_search$V1,paired=T)
###linear search
t.test(c.linear.recursive$time,scheme_linear_search$V1,paired=T)





##Iterative vs recursive in C
c.insertion.iterative<-c_sort[which(c_sort$algorithm == "insertion_iterative"),]
c.insertion.iterative<-c.insertion.iterative[c(1:490),]

c.linear.iterative<-c_search[which(c_search$algorithm == "linear_iterative"),]
c.linear.iterative<-c.linear.iterative[c(1:490),]

c.binary.iterative<-c_search[which(c_search$algorithm == "binary_iterative"),]
c.binary.iterative<-c.binary.iterative[c(1:490),]

c.merge.iterative<-c_sort[which(c_sort$algorithm == "merge_iterative"),]
c.merge.iterative<-c.merge.iterative[c(1:490),]

###########################Iterative is faster for all but binary
###########################Both are pretty much the same for binary
###insertion sort
t.test(c.insertion.recursive$time,c.insertion.iterative$time,paired=T)
###linear search
t.test(c.linear.recursive$time,c.linear.iterative$time,paired=T)
###binary search
t.test(c.binary.recursive$time,c.binary.iterative$time,paired=T)
###merge sort
t.test(c.merge.recursive$time,c.merge.iterative$time,paired=T)





##Different alg in C
######################merge is faster
###insertion vs merge sort recursive
t.test(c.insertion.recursive$time,c.merge.recursive$time,paired=T)
###insertion vs merge sort iterative
t.test(c.insertion.iterative$time,c.merge.iterative$time,paired=T)
######################binary is faster
###binary vs linear search recursive
t.test(c.binary.recursive$time,c.linear.recursive$time,paired=T)
###binary vs linear search iterative
t.test(c.binary.iterative$time,c.linear.iterative$time,paired=T)




##Iterative vs recursive in Python
########################iterative is faster
###binary search
t.test(1000000*(bsr_python$time),1000000*(bsi_python$time),paired=T) 



##Different alg in Python
########################binary is faster
###binary vs linear search (iterative)
t.test(1000000*(bsi_python$time),1000000*(lsi_python$time),paired=T) 



##Python vs scheme
#######################Python is faster
###binary search (recursive)
t.test(1000000*(bsr_python$time),scheme_binary_search$V1,paired=T)


##Python vs C
######################C is always faster
###binary search recursive
t.test(1000000*(bsr_python$time),c.binary.recursive$time,paired=T)
###binary search iterative
t.test(1000000*(bsi_python$time),c.binary.iterative$time,paired=T)
###linear search iterative
t.test(1000000*(lsi_python$time),c.linear.iterative$time,paired=T)






#Plots
##Insertion vs merge in Scheme
plot(V1~V2,data = scheme_insertion_sort, pch=1, log="y", ylim=c(2e+03,1e+09),
     xlab="input size", ylab="log of run time", main="Insertion vs merge sort in Scheme")
lines(V1~V2,data = scheme_merge_sort, type="p",pch=20)
legend("topleft", c("insertion", "merge"),pch=c(1,20))

##Insertion sort by iteration vs merge in C
plot(time~input,data = c.insertion.recursive, pch=1,
     xlab="input size", ylab="run time", main="Iteration vs recursion insertion sort in C")
lines(time~input,data = c.insertion.iterative, type="p",pch=20)
legend("topleft",c("recursion", "iteration"),pch=c(1,20))

##Linear search by iteration in C vs Python
plot(1e+6*time~input,data = lsi_python, pch=1,
     xlab="input size", ylab="run time", main="Iterative linear search in C vs Python")
lines(time~input,data = c.linear.iterative, type="p",pch=20)
legend("topleft",c("Python", "C"),pch=c(1,20))

##Binary search by recursion in Python and C
plot(V1~V2,data = scheme_binary_search, pch=1,
     xlab="input size", ylab="run time", main="Recursive binary search in Python vs Scheme")
lines(1e+06*time~input,data = bsr_python, type="p",pch=20)
legend("topleft",c("Scheme", "Python"),pch=c(1,20))


##Recursive merge sort in all three lgs
plot(1e+06*time~input,data = msr_python, pch=1,
     xlab="input size", ylab="run time", main="Recursive merge sort in all three languages", 
     log="y",ylim=c(100,5e+06))
lines(V1~V2,data = scheme_merge_sort, type="p",pch=20)
lines(time~input,data = c.merge.recursive, type="p",pch=8)
legend("topleft",c("Python", "Scheme","C"),pch=c(1,20,8))





###Recursive insertion sort in C with fitted quadratic model
c.r.insertion.model<-lm(time~I(input^2),data=c.insertion.recursive)
plot(time~input,data=c.insertion.recursive,xlab="input size", ylab="run time",
     main="Recursive insertion sort in C with fitted quadratic model")
curve(coef(c.r.insertion.model)[2]*x^2+coef(c.r.insertion.model)[1],0,5e+5,add=T)
