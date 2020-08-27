n = int(input())
trd = []
buy = {}
give = {}

transaction = {}

for i in range(n):
  a, b, c, d, e = input().split()
  temp = {}
  temp['id'] = int(a)
  temp['type'] = b
  temp['company'] = c
  temp['price'] = float(d)
  temp['quantity'] = int(e)
  trd.append(temp)

for t in trd:
  if t['type'] == 'Sell':
    if t['company'] in give:
      give[t['company']].append([t['price'],t['quantity']])
    else:
      give[t['company']] = [[t['price'],t['quantity']]]
  else:
    if t['company'] in buy:
      buy[t['company']].append([t['price'],t['quantity']])
    else:
      buy[t['company']] = [[t['price'],t['quantity']]]

for b in buy.keys():
  for j in buy[b]:
    if b in give.keys():
      for i in give[b]:
        if i[0] <= j[0]:
          q = min(j[1],i[1])
          j[1]-=q
          i[1]-=q
          transaction[b] = i[0]

if transaction:
  for i in transaction.keys():
    print(i+":"+str(int(transaction[i])))
else:
  print("Stocks not traded",end='')