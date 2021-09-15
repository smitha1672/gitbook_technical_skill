# Using mail Command

```text
$ sudo apt-get install mailutils
```

Now its time to send an email attachment using mail command a shown <br//

```text
$ echo "Message Body Here" | mail -s "Subject Here" user@example.com -A backup.zip
```

```text
-s – specifies the message subject.
-A – helps to attach a file.
```

You can as well send an existing message from a file as follows: <br/>

```text
mail -s "Subject here" -t user@example.com -A backup.zip < message.txt
```
