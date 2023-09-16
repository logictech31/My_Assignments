db=connect('mongodb://localhost/bdt_a3');
db.bdt_a3.insertMany([{prn:63, Name:'Hrushikesh', Salary:33000}, {prn:2, Name:'Adam', Salary:41444}, {prn:3, Name:'HP', Salary:55020}, {prn:1, Name:'Sample', Salary:99999}, {prn:7, Name:'Aditya', Salary:88500}, {prn: 8, Name: 'Ishan', Salary: 33000}, {prn: 22, Name: 'Parth', Salary: 32000}]);
db.bdt_a3.find();
db.bdt_a3.aggregate({$group:{_id:"$Name","sum":{$sum:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","avg": {$avg:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","min": {$min:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","max": {$max:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","aggr1": {$first:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","pushaggr": {$push:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","count": {$sum:1}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","addToSet": {$addToSet:"$Salary"}}});
db.bdt_a3.createIndex({'Name':1});
db.bdt_a3.getIndexes();
db.bdt_a3.dropIndex({'Name':1})