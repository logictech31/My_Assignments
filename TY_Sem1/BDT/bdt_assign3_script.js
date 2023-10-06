db=connect('mongodb://localhost/bdt_a3');
db.bdt_a3.insertMany([{RollNo:'1', Name:'Hrushikesh', Salary:'1500'}, {RollNo:'2', Name:'Erwin', Salary:'4500'}, {RollNo:'3', Name:'ABC', Salary:'5500'}, {RollNo:'1', Name:'Salad', Salary:'6500'}, {RollNo:'7', Name:'Tofu', Salary:'8500'}]);
db.bdt_a3.find();
db.bdt_a3.aggregate({$group:{_id:"$Name","sum":{$sum:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","avg": {$avg:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","min": {$min:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","max": {$max:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","firstaggr": {$first:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","pushaggr": {$push:"$Salary"}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","count": {$sum:1}}});
db.bdt_a3.aggregate({$group:{_id:"$Name","addToSet": {$addToSet:"$Salary"}}});
db.bdt_a3.createIndex({'Name':1});
db.bdt_a3.getIndexes();
db.bdt_a3.dropIndex({'Name':1})