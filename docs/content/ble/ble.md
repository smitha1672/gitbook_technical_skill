#
## Blooth Low Engery

[ble-microchip](http://microchipdeveloper.com/wireless:ble-phy-layer)

### The BLE protocol stack

<img src="http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.s140.sds/dita/softdevices/s130/Images/bt_stack_arch_s132_s140.svg"
width="70%"
height="70%"
alt="ble protocol stack"
align=center />

### Physical Layer

+ Frequency Bands

```text
The radio uses the 2.4 GHz ISM (Industrial, Scientific, and Medical) band to communicate and divides
this band into 40 channels on 2 MHz spacing from 2.4000 GHz to 2.4835 GHz, starting at 2402 MHz:
```

<img src="https://microchip.wikidot.com/local--files/wireless:ble-phy-layer/ble-phy-channel-assignment.png"
width="80%"
height="80%"
alt="frequecny channels"
align=center />

+ Channel Arrangement

```text
The 40 channels are divided into 3 Advertising Channels (Ch. 37, 38, 39),
and 37 Data Channels (Ch.0-36).
```

> Advertising Channel Usage
```text
Device Discovery
Connection Establishment
Broadcast Transmissions
```

> Data Channel Usage
```text
Bidirectional communication between connected devices
Adaptive frequency hopping used for subsequent connection events
```

+ Modulation & Data Rate

```text
When transmitting data, the BLE radio transmits at 1 Mbps, with 1 bit per symbol. The radio is
optimized for sending small chunks of data quickly.

The BLE radio uses Gaussian frequency-shift keying (GFSK), whereby the data pulses are filtered with
a Gaussian filter before being applied to alter the carrier frequency, in order to make the
frequency transitions smoother.

Note: BLE protocol overhead limits overall data throughput to significantly less than 1 Mbps.
```

### Link Layer
To do this, it is primarily concerned with channels, packets, discovery, and connection procedures.

#### Channels

> Advertising Channel Usage
```text
Device Discovery
Connection Establishment
Broadcast Transmissions
```

> Data Channel Usage
```text
Bidirectional communication between connected devices
Adaptive frequency hopping used for subsequent connection events
```

#### Roles and States

Link Layer perspective, the following role pairs are defined `Advertiser/Scanner (Initiator)`,
`Slave/Master`, `Broadcaster/Observer`

+ Unicast (Peer-Peer) Connection

<img src="https://microchip.wikidot.com/local--files/wireless:ble-link-layer-roles-states/roles-unicast-discovery.png"
width="80%"
height="80%"
alt="unicast.1"
align=center />

<br>
<img src="https://microchip.wikidot.com/local--files/wireless:ble-link-layer-roles-states/roles-unicast-connecting.png"
width="80%"
height="80%"
alt="unicast.2"
align=center />

<br>
<img src="https://microchip.wikidot.com/local--files/wireless:ble-link-layer-roles-states/roles-unicast-connected.png"
width="80%"
height="80%"
alt="unicast.3"
align=center />

`unicast.1`, diagram depicts two BLE hosts, initially in a Standby (unconnected) state. They enter
a Discovery state whereby the `device` wishing to be discovered becomes the `Advertiser` and the host
wishing to connect becomes a `Scanner`. The Advertiser sends advertising packets containing basic
information about the host. All Scanners receive these packets.

`unicast.2`, at some point, the Scanner (after filtering/analyzing information contained in the advertising
packets) becomes an Initiator and decides to initiate a connection with a specific advertiser. This
is known as the Connecting phase and is highlighted by the Initiator sending a `CONNECT_REQ`
advertising packet to the Advertiser

`unicast.3`, finally, the Advertiser accepts the connection request, thus becoming the Slave while
the Initiator becomes the Master. This is known as the Connected phase

#### Device Address

Bluetooth Device Address. This `48-bit (6-byte)` number `uniquely` identifies a device among peers.
There are two types of device addresses and one or both can be set on a device.

<img src="https://microchip.wikidot.com/local--files/wireless:ble-link-layer-address/ble-device-address-types.png"
width="80%"
height="80%"
alt="device address"
align=center />

Each discovery/connection procedure must be performed using one of the two types and is specified by
the host
