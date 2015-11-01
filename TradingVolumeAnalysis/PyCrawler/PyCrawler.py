from urllib import request

#retrieve data for JPmorgan, Goldman Sachs, Morgan Stanley, Deutsche Bank, Citigroup, Barclays, UBS, Lazard and Wells Fargo
tickers = ['JPM','GS','MS','DB','C','BCS', 'UBS', 'LAZ', 'WFC']

for t in tickers:
    #for each ticker, get the data from 1999 to 2015  
    data = request.urlopen("http://real-chart.finance.yahoo.com/table.csv?s=%s&d=9&e=31&f=2015&g=d&a=4&b=4&c=1999&ignore=.csv"%t)
    csv = str(data.read()).strip("b'").split("\\n")
    #write data to file
    f = open("%s_data.csv"%t,"w")
    for row in csv:
        #get trading volume data by preprocessing
        if row:
            vol = row.split(',')[5]
            f.write(vol +"\n")
    f.close()



