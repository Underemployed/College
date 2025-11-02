

mydata=select(iris,c(1,2,3,4))
View(mydata)
summary(mydata)
cm=cor(mydata)
cm
index=sample(2,nrow(mydata),replace=TRUE,prob=c(0.7,0.3))
index
Training=mydata[index==1,,]
Testing=mydata[index==2,,]
model=lm(Petal.Length~Sepal.Length+Sepal.Width,Training)
Predict=predict(model,Testing)
error=MAPE(Predict,Testing$Petal.Length) 
1-error