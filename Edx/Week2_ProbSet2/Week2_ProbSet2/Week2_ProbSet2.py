balance = 4213
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
month = 1
totalPaid = 0
while month <= 12:
    print "{0} {1}".format("Month:",month)
    print "{0} {1}".format("Minimum monthly payment:",round(balance * monthlyPaymentRate,2))
    minimumAmount = balance * monthlyPaymentRate
    totalPaid+= minimumAmount
    remainingAmount = balance - minimumAmount
    balance = remainingAmount + ((annualInterestRate / 12.0) * remainingAmount)
    print "{0} {1}".format("Remaining balance:",round(balance,2))
    month+=1

print "Total paid: {0}".format(round(totalPaid,2))
print "{0} {1}".format("Remaining balance:",round(balance,2))

