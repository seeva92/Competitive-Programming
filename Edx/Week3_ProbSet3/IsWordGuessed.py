def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    for letter in lettersGuessed:
        secretWord = secretWord.replace(letter,"")
    if len(secretWord) is 0:
        return True
    return False

secretWord = 'apple' 
lettersGuessed = ['e', 'i', 'k', 'p', 'l', 'a']
print isWordGuessed(secretWord, lettersGuessed)

def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    s = 'abcdefghijklmnopqrstuvwxyz'
    return s.translate(None,str(lettersGuessed))

print getAvailableLetters(lettersGuessed)