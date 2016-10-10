balance = 3329
annualInterestRate = 0.2
monthlyPaymentRate = 0.04
minimumAmount = 10
temp = balance
while True:
    month = 1
    totalPaid = 0
    balance = temp
    while month <= 12 and balance > 0:
        #print "{0} {1}".format("Month:",month)
        #print "{0} {1}".format("Minimum monthly payment:",round(balance *
        #monthlyPaymentRate,2))
        #minimumAmount = balance * monthlyPaymentRate
        remainingAmount = balance - minimumAmount
        balance = remainingAmount + ((annualInterestRate / 12.0) * remainingAmount)
        month+=1

    if balance <= 0:
        break
    minimumAmount+=10

print "Lowest Payment: {0}".format(round(minimumAmount,2))

