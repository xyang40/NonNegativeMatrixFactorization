
from urllib import request

# Retrieve the webpage as a string
response = request.urlopen("http://www.google.com/finance/historical?cid=22144&startdate=Nov+1,+2011&enddate=Nov+14,+2011&output=csv")
csv = response.read()

# Save the string to a file
csvstr = str(csv).strip("b'")

lines = csvstr.split("\\n")
f = open("historical.csv", "w")
for line in lines:
   f.write(line + "\n")
f.close()