balance = 999999
annualInterestRate = 0.18
monthlyPaymentRate = annualInterestRate/12.0

lowerBound = balance/12.0000000
upperBound = (balance * ((1 + monthlyPaymentRate)**12))/12.0000000
originalBalance = balance
while True:
    month = 1
    totalPaid = 0
    balance = originalBalance
    minimumAmount = lowerBound + (upperBound - lowerBound)/2

    while month <= 12:
        remainingAmount = balance - minimumAmount
        balance = remainingAmount + ((annualInterestRate / 12.0) * remainingAmount)
        month+=1

    
    if (balance< -0.01):
        upperBound = minimumAmount
    elif balance > 0.01:
        lowerBound = minimumAmount
    else:
        break


print "Lowest Payment: {0}".format(round(minimumAmount,2))

