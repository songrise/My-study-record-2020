library("ggplot2")

age = read.table("./q4_data/age.txt")
height = read.table("./q4_data/height.txt")

#regressionLine = lm(formula = height$V1 ~ age$V1)
q4data = data.frame(age,height)
ggplot(data=q4data,aes(x=age$V1,y=height$V1))+geom_smooth(method='lm',color="red",se=FALSE)+geom_point(color = "blue")+xlab("Age(year)")+ylab("Height(meter)")+ggtitle("Age vs. Height")