cube = float(input())
epsilon = 0.01
num_guesses = 0
if cube < 1:
    low = cube
    high = 1
else:
    low = 0
    high = cube
guess = (high + low) / 2.0
while abs(guess**3 - cube) >= epsilon:
    if guess**3 < cube:
        low = guess
    else:
        high = guess
    guess = (high + low) / 2.0
    num_guesses += 1
print('num_guesses ==', num_guesses)
print(guess, '**3 ~=', cube)
