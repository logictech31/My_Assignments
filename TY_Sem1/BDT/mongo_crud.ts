let client = require('mongodb').MongoClient
let url = 'mongodb://localhost:27017/'

client.connect(url, (err, db) => {
    if(err) {
        throw err
    }
    let dbo = db.db('sampledb')
    let document = {
        FName: 'Javascript',
        LName: 'Typescript',
        Panel: 'TS',
        Extension: '.ts'
    }
    dbo.collection('Employee').insertOne(document, (err, res) => {
        if(err) throw err
        console.log('Inserted 1 document')
    })
    db.close()
})
