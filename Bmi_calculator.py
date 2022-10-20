height = float(input("Enter your height in cm: "))

if height <= 1:
    print("Enter valid height!!!!")
    quit()

# Adding an easter-egg like fun exception for a typo (or really the tallest person!)
if height > 272:
    print("Congratulations! You beat the world record for the tallest person!")
    print("Carry on and find your BMI")
    
weight = float(input("Enter your weight in kg: "))
if weight <= 1:
    print("Enter valid weight!!!!")
    quit()

BMI = weight / (height/100)**2
print(f"You BMI is {BMI}")
if BMI <= 18.4:
    print("You are underweight.")
elif BMI <= 24.9:
    print("You are healthy.")
elif BMI <= 29.9:
    print("You are over weight.")
elif BMI <= 34.9:
    print("You are severely over weight.")
elif BMI <= 39.9:
    print("You are obese.")
else:
    print("You are severely obese.")
