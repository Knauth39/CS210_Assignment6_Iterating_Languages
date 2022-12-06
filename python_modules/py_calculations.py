import re
import string

'''
Function to call when program is exited
@return Print statement 
'''
def exitStatement():
    print("Goodbye and have a splendid day!")

'''
Function to call when user chooses to view a multiplication table 
@param  userNumber - input from user in menu selction
@return Multiplication table of user's number up to factor 10 
'''
def MultiplyFunction(userNumber):
    factor          = userNumber    # Assigns user input to variable
    counter         = 10            # Initializes counter for table 
    string_x        = " x "         # Stores multiplication symbol in string variable
    string_equal1   = " = "         # Stores equal sign symbol in string variable
    string_equal2   = "  = "        # Stores equal sign symbol with additional preceding space in string variable
    string_complete = "Keep going!" # Stores completion string

    print("Multiplication Table for Number: ", factor)
    # Prints multiplication table - counter starts at 10 and decrements until 1 
    while counter > 0:
        product = factor*counter
        # Aligns product column up to three digits in length based on counter length - one or two digits
        if len(str(abs(counter))) > 1:
            print(factor, string_x, counter, string_equal1, product)
        else:
            print(factor, string_x, counter, string_equal2, product)
        counter -= 1

        return string_complete

'''
Function to call when user chooses to double an integer
@param  userNumber - input from user in menu selction
@return Value of user number doubled (multiplied by 2)
'''
def DoubleValue(userNumber):
    return userNumber*2
    



    
