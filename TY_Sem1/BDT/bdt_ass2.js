db = connect( 'mongodb://localhost/sampledb');
db.createCollection('crud_collection');
db.crud_collection.insertMany([{prn: 1032221208 ,name: 'Hrushikesh Pandit'}, {prn: 0, name: 'Sample'}]);
db.crud_collection.find().pretty();
db.crud_collection.updateOne({prn: 0}, {$set: {prn: 55}})
db.crud_collection.find().pretty();
db.crud_collection.deleteOne({prn: 55});
db.crud_collection.drop();