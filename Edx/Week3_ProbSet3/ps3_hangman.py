# 6.00 Problem Set 3
# 
# Hangman game
#

# -----------------------------------
# Helper code
# You don't need to understand this helper code,
# but you will have to know how to use the functions
# (so be sure to read the docstrings!)

import random
import string
from string import maketrans
WORDLIST_FILENAME = "words.txt"

def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print "Loading word list from file..."
    # inFile: file
    inFile = open(WORDLIST_FILENAME, 'r', 0)
    # line: string
    line = inFile.readline()
    # wordlist: list of strings
    wordlist = string.split(line)
    print len(wordlist), "words loaded."
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

# end of helper code
# -----------------------------------

# Load the list of words into the variable wordlist
# so that it can be accessed from anywhere in the program
wordlist = loadWords()

def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''
    # FILL IN YOUR CODE HERE...
    if len(secretWord.translate(None,str(lettersGuessed))) == 0:
        return True
    return False



def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''
    # FILL IN YOUR CODE HERE...
    invalidGuess = secretWord.translate(None,str(lettersGuessed))
    temp = secretWord
    for letter in invalidGuess:
        temp = temp.replace(letter,"_ ")
    return temp



def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    s = 'abcdefghijklmnopqrstuvwxyz'
    return s.translate(None,str(lettersGuessed))
    

def hangman(secretWord):
    # '''
    # secretWord: string, the secret word to guess.

    # Starts up an interactive game of Hangman.

    # * At the start of the game, let the user know how many 
    #   letters the secretWord contains.

    # * Ask the user to supply one guess (i.e. letter) per round.

    # * The user should receive feedback immediately after each guess 
    #   about whether their guess appears in the computers word.

    # * After each round, you should also display to the user the 
    #   partially guessed word so far, as well as letters that the 
    #   user has not yet guessed.

    # Follows the other limitations detailed in the problem write-up.
    # '''
    # # FILL IN YOUR CODE HERE...
    print "Welcome to the game, Hangman!"
    print "I am thinking of a word that is {0} letters long.".format(len(secretWord))
    print "-------------"
    guessCount = 8
    lettersGuessed = []
    while guessCount > 0 and isWordGuessed(secretWord,lettersGuessed) == False:
        print "You have {0} guesses left.".format(guessCount)
        print "Available letters: {0}".format(getAvailableLetters(lettersGuessed))
        print "Please guess a letter: ",
        letter = str(raw_input()).lower()
        if letter not in lettersGuessed:
            lettersGuessed.append(letter)
            if letter in secretWord:
                print "Good guess: {0}".format(getGuessedWord(secretWord,lettersGuessed))
            else:
                print "Oops! That letter is not in my word: {0}".format(getGuessedWord(secretWord,lettersGuessed))
                guessCount-=1
        else:
            print "Oops! You've already guessed that letter: {0}".format(getGuessedWord(secretWord,lettersGuessed))
        print "-------------"

    if isWordGuessed(secretWord,lettersGuessed):
        print "Congratulations, you won!"
    else:
        print "Sorry, you ran out of guesses. The word was else."



# When you've completed your hangman function, uncomment these two lines
# and run this file to test! (hint: you might want to pick your own
# secretWord while you're testing
secretWord = chooseWord(wordlist).lower()
hangman(secretWord)

