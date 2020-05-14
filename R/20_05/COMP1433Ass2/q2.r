
############Q2.(1)##############
q2data = read.table("./q2_data/scores.csv", header = TRUE, sep = ',')

############Q2.(2)##############
print("The statistics for science scores are:")
print(paste("mean=",mean(q2data$Science)))
print(paste("standard deviation=",sd(q2data$Science)))
print(paste("median score=",median(q2data$Science)))
print(paste("mininum score=",min(q2data$Science)))
print(paste("maxium score=",max(q2data$Science)))

############Q2.(3)##############
mathMean = mean(q2data$Math)
mathSD = sd(q2data$Math)
sciMean = mean(q2data$Science)
sciSD = sd(q2data$Science)
engMean = mean(q2data$English)
engSD = sd(q2data$English)

for (i in c(1:nrow(q2data))) {
    #inplace modify q2data.
    q2data$Math[i] =  ((q2data$Math[i] - mathMean)/mathSD)
    q2data$Science[i] =  ((q2data$Science[i] - sciMean)/sciSD)
    q2data$English[i] =  ((q2data$English[i] - engMean)/engSD)
}

############Q2.(4)##############
for (i in c(1:nrow(q2data))) {
    #first convert to "characer" type, then use " " to split that string.
    q2data$First_Name[i] = strsplit(as.character(q2data$StuName[i]),split=" ")[[1]][1]
    q2data$Last_Name[i] = strsplit(as.character(q2data$StuName[i]),split=" ")[[1]][2]
}

############Q2.(5)##############
overallGrades <- vector()
for (i in c(1:nrow(q2data))) {
    #calculate weighed overall score.
    overallGrades[i] = q2data$Math[i]*0.3 + q2data$Science[i]*0.4 + q2data$English[i]*0.3
}

sortedGrades = sort(overallGrades,decreasing = TRUE)

for (i in c(1:nrow(q2data))) {
    #calculate letter grades according to rank of weighed overall score.
    rank = match(overallGrades[[i]],sortedGrades)

    if (rank <= nrow(q2data) * 0.25) {
        q2data$Grades[i] = 'A'
    }
    else if (rank <= nrow(q2data) * 0.50) {
        q2data$Grades[i] = 'B'
    }
    else if (rank <= nrow(q2data) * 0.75) {
        q2data$Grades[i] = 'C'
    }
    else {
        q2data$Grades[i] = 'D'
    }
}

############Q2.(5)##############
write.table(q2data,file = "./newscores.csv")
