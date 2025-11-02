> help("a = read.csv("a.csv")")
Error: unexpected symbol in "help("a = read.csv("a.csv"
> a = read.csv("a.csv")
Error in file(file, "rt") : cannot open the connection
In addition: Warning message:
In file(file, "rt") : cannot open file 'a.csv': No such file or directory
> a = read.csv("C:\Users\nithi\Documents\gitprojects\College\R language\a.csv")
Error: '\U' used without hex digits in character string (<input>:1:18)
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> 
> 
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> View(a)
> plot(a$Name,a$Score)
Error in plot.window(...) : need finite 'ylim' values
In addition: Warning messages:
1: In xy.coords(x, y, xlabel, ylabel, log) : NAs introduced by coercion
2: In min(x) : no non-missing arguments to min; returning Inf
3: In max(x) : no non-missing arguments to max; returning -Inf
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> View(a)
> plot(a$Name,a$Marks)
Error in plot.window(...) : need finite 'xlim' values
In
1: In xy.coords(x, y, xlabel, ylabel, log) : NAs introduced by coercion
2: In min(x) : no non-missing arguments to min; returning Inf
3: In max(x) : no non-missing arguments to max; returning -Inf
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> plot(a$Hours,a$Marks)
> pairs(a$Hours,a$Marks, a$Names)
Error in match.fun(panel) : 
  'a$Names' is not a function, character or symbol
> pairs(~$Hours+a$Marks+a$Names,in_data =data)
Error: unexpected '$' in "pairs(~$"
> pairs(~$Hours+a$Marks+a$Names,data =a)
Error: unexpected '$' in "pairs(~$"
> pairs(~Hours+Marks+Names,data =a)
Error in eval(predvars, data, env) : object 'Names' not found
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> plot(a$Hours,a$Marks)
> pairs(~Hours+Marks+Names,data=a,cex )
Error in pairs.default(mf, ...) : non-numeric argument to 'pairs'
> pairs(~Hours+Marks+Names,data=a,cex )
Error in pairs.default(mf, ...) : non-numeric argument to 'pairs'
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> plot(a$Hours,a$Marks)
> pairs(~Hours+Marks+Names,data=a)
Error in pairs.default(mf, ...) : non-numeric argument to 'pairs'
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> plot(a$Hours,a$Marks)
> pairs(~Hours+Marks+Age,data=a)
> model = lm(a$Hours ~a$Marks)
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> 
> 
> 
> model = lm(a$Hours ~a$Marks)
> 
> model = lm(a$Hours ~a$Marks)
> pred =  predict(model,data.frame(Hour=6))
Warning message:
'newdata' had 1 row but variables found have 10 rows 
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> 
> View(a)
> 
> model = lm(Hours ~Marks, data)
Error in model.frame.default(formula = Hours ~ Marks, data = data, drop.unused.levels = TRUE) : 
  'data' must be a data.frame, environment, or list
> pred =  predict(model,data.frame(Hours=6))
Warning message:
'newdata' had 1 row but variables found have 10 rows 
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> 
> View(a)
> 
> model = lm(Hours ~Marks, data)
Error in model.frame.default(formula = Hours ~ Marks, data = data, drop.unused.levels = TRUE) : 
  'data' must be a data.frame, environment, or list
> pred =  predict(model,newdata= data.frame(Hours=6))
Warning message:
'newdata' had 1 row but variables found have 10 rows 
> 
> print(pred)
       1        2        3        4        5        6        7        8 
3.726027 4.972603 2.479452 4.260274 5.506849 3.191781 4.616438 4.082192 
       9       10 
3.369863 4.794521 
> View(a)
> 
> model = lm(Marks~Hours+Age, data)
Error in model.frame.default(formula = Marks ~ Hours + Age, data = data,  : 
  'data' must be a data.frame, environment, or list
> pred =  predict(model,newdata= data.frame(Hours=6))
Warning message:
'newdata' had 1 row but variables found have 10 rows 
> 
> print(pred)
       1        2        3        4        5        6        7        8 
3.726027 4.972603 2.479452 4.260274 5.506849 3.191781 4.616438 4.082192 
       9       10 
3.369863 4.794521 
> 
> a = read.csv("C:\\Users\\nithi\\Documents\\gitprojects\\College\\R language\\a.csv")
> 
> View(a)
> index = sample(2, nrow(a), replace = TRUE, prob = c(0.7, 0.3))
> tr = a[index == 1]
Error in `[.data.frame`(a, index == 1) : undefined columns selected
> te = a[index == 2]
Error in `[.data.frame`(a, index == 2) : undefined columns selected
> model = lm(Marks~Hours+Age, tr)
Error in eval(mf, parent.frame()) : object 'tr' not found
> pred =  predict(model,te)
Error: object 'te' not found
> error=MAPE(pred,te$Hours)
Error in MAPE(pred, te$Hours) : could not find function "MAPE"
> 1-error
Error: object 'error' not found
> cm = cor(a)
Error in cor(a) : 'x' must be numeric
> cm
function (x) 
2.54 * x
<bytecode: 0x000001e7acf98f58>
<environment: namespace:grDevices>
> summary(a)
    Names               Marks         Subjects             Hours     
 Length:10          Min.   :78.00   Length:10          Min.   :3.00  
 Class :character   1st Qu.:83.50   Class :character   1st Qu.:3.25  
 Mode  :character   Median :87.50   Mode  :character   Median :4.00  
                    Mean   :87.10                      Mean   :4.10  
                    3rd Qu.:90.75                      3rd Qu.:4.75  
                    Max.   :95.00                      Max.   :6.00  
      Age       
 Min.   :18.00  
 1st Qu.:18.25  
 Median :19.00  
 Mean   :19.20  
 3rd Qu.:20.00  
 Max.   :21.00  
> 
