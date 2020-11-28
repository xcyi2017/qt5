function dbInit() {
    var db = LocalStorage.openDatabaseSync("mySQLite", "1.0",
                                           "This is only for demo", 1000000)
    try {
        db.transaction(function (tx) {
            tx.executeSql(
                        'CREATE TABLE IF NOT EXISTS myclass (name text, teacher text)')
        })
        console.log("Table Created!")
    } catch (err) {
        console.log("Error creating table in database: " + err)
    }
    ;
//    dbInsert("初一一班", "杨老师");
//    dbInsert("初一二班", "周老师");
//    dbInsert("初一三班", "谢老师");
//    dbInsert("初一四班", "张老师");
//    dbInsert("初一五班", "刘老师");
//    dbInsert("初一六班", "陈老师");
}

function dbGetHandle() {
    try {
        var db = LocalStorage.openDatabaseSync("mySQLite", "1.0",
                                               "This is only for demo", 1000000)
    } catch (err) {
        console.log("Error opening database: " + err)
    }
    return db
}

function dbInsert(name, teacher) {
    var db = dbGetHandle()
    var rowid = 0
    db.transaction(function (tx) {
        tx.executeSql('INSERT INTO myclass VALUES(?, ?)', [name, teacher])
        var result = tx.executeSql('SELECT last_insert_rowid()')
        rowid = result.insertId
    })
    return rowid
}

function dbReadAll() {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        var results = tx.executeSql(
                    'SELECT rowid,name,teacher FROM myclass order by rowid desc')
        for (var i = 0; i < results.rows.length; i++) {
            listModel.append({
                                 "id": results.rows.item(i).rowid,
                                 "name": results.rows.item(i).name,
                                 "teacher": results.rows.item(i).teacher
                             })
        }
    })
}

function dbUpdate(name, teacher, Prowid) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('update myclass set name=?, teacher=? where rowid = ?',
                      [name, teacher, Prowid])
    })
}

function dbDeleteRow(Prowid) {
    var db = dbGetHandle()
    db.transaction(function (tx) {
        tx.executeSql('delete from myclass where rowid = ?', [Prowid])
    })
}
