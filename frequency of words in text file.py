# an example
# file=open("School.txt",'w')
# file.writelines(["My school name is Kendriya Vidyalaya","It has a very big campus.","It is affilliated with CBSE"])
# file.close()
# file=open("School.txt",'r')
file=open("<filename>.txt",'r')
count=0
for line in file:
    words=line.split()
    for word in words:
        word=word.strip()
        count+=len(word)
    print("line")
print("Number of words = ",count)
file.close()
