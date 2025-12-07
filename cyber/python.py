
# lists are mutable and can contain duplicate 

my_list = [1,2,3,4,5] 
my_list.append(4)
my_list.insert(1,10)
my_list.pop()
my_list.sort()
print(my_list)

# tuples are immutable , ordered and can contail duplicates 

my_tuple = (1,2,3,4,2,3)
print(my_tuple.count(2))
print(my_tuple.index(3))


# key value pairs , unordered , keys are unique , mutable 


student = {"name": "Yash", "age": 20}
student["branch"] = "CSE"
print(student.get("name"))
student.update({"age" : 21})
# student.pop("branch")
print(student)

#stirngs are immutalbe ordered and sequence of characters 
# upper lower strip split join replace find count startwith endwith

s = "hello yash"

with open ( "sample.txt" , "w" ) as f :
    f.write("hello yash !")

with open ( "sample.txt" , "r" ) as f :
    content = f.read 
    print(content)

with open("sample.txt", "a") as f:
    f.write("\nThis is extra line.")


with open("sample.txt", "r") as file:
    for line in file:
        print(line ,end = ' ')

#list dictionary and sets are mutable 
#tuple and strings are not mutable 