points = data.frame(x = c(5,4,3,2,1), y = c(2,1.5,1,1,0.5) )

points.regression = lm(y~x, data = points)
print(points.regression)

point.summary = summary(points.regression)
print(point.summary[8])#R-suqare