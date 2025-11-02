a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")

View(a)
index = sample(2, nrow(a), replace = TRUE, prob = c(0.7, 0.3))
tr = a[index == 1]
te = a[index == 2]
model = lm(Marks~Hours+Age, tr)
pred =  predict(model,te)
error=MAPE(pred,te$Hours)
1-error

cm = cor(a)
cm
summary(a)