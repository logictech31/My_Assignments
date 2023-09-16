db = connect('mongodb://localhost/sampledb');
db.createCollection('Album');
db.Album.insertMany([{Type: 'Sufi', Artist: 'Travis Scott', ReleaseDate: 2014, TrackList: ['TrackA', 'TrackB'], Cast: ['John Doe']}, {Type: 'Country-Pop'}, {Type: 'Pop', Artist: 'A.R. Rahman', ReleaseDate: 1999, TrackList: ['Hello', 'Hi'], Cast: ['Ranbir Kapoor']}])
db.Album.find({ReleaseDate: {$gt: 2000}});
db.Album.find({ReleaseDate: 1999});
db.Album.deleteMany({Artist: 'A.R. Rahman'});
db.Album.updateMany({Type: 'Sufi'}, {$set: {Type: 'New Sufi'}});
db.Album.find().pretty();
db.Album.drop();