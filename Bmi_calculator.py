height = float(input("Enter your height in cm: "))
while (height <= 1):
    print("Enter valid height!")
    height = float(input("Enter your height in cm: "))

weight = float(input("Enter your weight in kg: "))
while (weight <= 1):
    print("Enter valid height!")
    weight = float(input("Enter your weight in kg: "))

BMI = float(weight / (height/100)**2)

print(f"\nYour BMI is {BMI:.2f}")
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
