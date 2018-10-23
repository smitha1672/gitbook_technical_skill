## Inter-Integrated Circuit, I2C

+ Start and Stop Condition

<img src="http://i2c.info/wp-content/images/i2c.info/start-stop.gif"
width="70%"
height="70%"
alt="i2c start and stop condition"
align=center />

+ Case 1

If the master only writes to the slave device then the data transfer direction is not changed.

<img src="http://i2c.info/wp-content/images/i2c.info/7-bit-address-writing.gif"
width="70%"
height="70%"
alt="7 bits address writing"
align=center />

+ Case 2

If the master only needs to read from the slave device then it simply sends the I2C address with the
R/W bit set to read. After this the master device starts reading the data.

<img src="http://i2c.info/wp-content/images/i2c.info/7-bit-address-reading.gif"
width="60%"
height="60%"
alt="7 bits address reading"
align=center />

+ Case 3

Sometimes the master needs to write some data and then read from the slave device. In such cases it
must first write to the slave device, change the data transfer direction and then read the device.
This means sending the I2C address with the R/W bit set to write and then sending some additional
data like register address. After writing is finished the master device generates repeated start
condition and sends the I2C address with the R/W bit set to read. After this the data transfer
direction is changed and the master device starts reading the data.

<img src="http://i2c.info/wp-content/images/i2c.info/7-bit-address-writing-reading.gif"
width="80%"
height="80%"
alt="7 bits address writing reading"
align=center />

+ CS5346 Control Port Timing, I2C Write

<img src="cs5346i2cwrite.png"
width="90%"
height="90%"
alt="CS5346 Control Port Timing, I²C Write"
align=center />

+ CS5346 Control Port Timing, I2C Read

<img src="cs5346i2cread.png"
width="90%"
height="90%"
alt="CS5346 Control Port Timing, I2C Read"
align=center />

