x =  c(300,400)
labels = c("Abhay","Gaurav")
colors =c("red","green")
pie(x, labels = labels, colors= colors , main ="Abhay X Gaurav\nCompatibility")



a =  data.frame(
	name = c("A","b","C"),
	marks = c(10,2,3)
)


a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
plot(a$Hours,a$Marks)
pairs(~Hours+Marks+Names,data=a)