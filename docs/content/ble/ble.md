#

## Bluetooth Basic v.s Bluetooth Low Engergy

<img src="blevsbtbasic_1.png"
width="100%"
height="100%"
alt="ble vs basic bt 1"
align=center />

<img src="blevsbtbasic_2.png"
width="90%"
height="90%"
alt="ble vs basic bt 2"
align=center />


## Blooth Low Engery

[ble-microchip](http://microchipdeveloper.com/wireless:ble-phy-layer)

### The BLE protocol stack

<img src="http://infocenter.nordicsemi.com/topic/com.nordic.infocenter.s140.sds/dita/softdevices/s130/Images/bt_stack_arch_s132_s140.svg"
width="70%"
height="70%"
alt="ble protocol stack"
align=center />

### Physical Layer-Controller

+ Frequency Bands

The radio uses the 2.4 GHz ISM (Industrial, Scientific, and Medical) band to communicate and divides
this band into 40 channels on 2 MHz spacing from 2.4000 GHz to 2.4835 GHz, starting at 2402 MHz:

<img src="https://microchip.wikidot.com/local--files/wireless:ble-phy-layer/ble-phy-channel-assignment.png"
width="80%"
height="80%"
alt="frequecny channels"
align=center />

+ Channel Arrangement

The 40 channels are divided into 3 Advertising Channels (Ch. 37, 38, 39),
and 37 Data Channels (Ch.0-36).

> Advertising Channel Usage
<br> 1. Device Discovery
<br> 2. Connection Establishment
<br> 3. Broadcast Transmissions

> Data Channel Usage
<br> 1. Bidirectional communication between connected devices
<br> 2. Adaptive frequency hopping used for subsequent connection events

+ Modulation & Data Rate

When transmitting data, the BLE radio transmits at `1 Mbps`, with `1 bit per symbol`. The radio is
optimized for sending small chunks of data quickly.

The BLE radio uses Gaussian frequency-shift keying (GFSK), whereby the data pulses are filtered with
a Gaussian filter before being applied to alter the carrier frequency, in order to make the
frequency transitions smoother.

Note: BLE protocol overhead limits overall data throughput to significantly less than 1 Mbps.

### Link Layer-Controller
To do this, it is primarily concerned with channels, packets, discovery, and connection procedures.

#### Channels

> Advertising Channel Usage
<br> 1. Device Discovery
<br> 2. Connection Establishment
<br> 3. Broadcast Transmissions

> Data Channel Usage
<br> 1. Bidirectional communication between connected devices
<br> 2. Adaptive frequency hopping used for subsequent connection events

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

#### Packet Types

Link Layer has only `one packet format` used for both `advertising channel` packets and `data
channel`

<img src="https://microchip.wikidot.com/local--files/wireless:ble-link-layer-packet-types/packet-format-top-level.png"
width="80%"
height="80%"
alt="packet overview"
align=center />

> PUD: BLE packet Protocol Data Unit size in specification v4.0 and v4.1 is 2-39 bytes.

#### Discovery(Advertising & Scanning)

todo

#### Connections

todo

#### Security

todo

### Generic Access Profile(GAP)-Host

The Generic Access Profile (GAP) modes and procedures form the cornerstone for Bluetooth Low Energy
(BLE) `control-plane` operations:
+ Discover and connect with peers
+ Broadcast data
+ Establish secure connections

GAP defines these and other fundamental operations in a standard, universally understood manner.
It's important to understand GAP, since most BLE implementations provide GAP APIs for applications
wishing to use this functionality.

#### Bluetooth Low Energy GAP Roles
todo

#### Bluetooth Low Energy GAP Modes and Procedures
todo

#### Bluetooth Low Energy Security Modes and Procedures
todo

### Generic Attribute Profile (GATT)-Host

The Generic Attribute Profile (GATT) establishes `how data will be organized and exchanged` over a
Bluetooth Low Energy (BLE) connection.

Certain use-case-specific profiles (GATT-Based Profiles) are standardized by the Bluetooth Special
Interest Group (SIG):
+ Heart Rate Profile
+ Proximity Profile
+ etc.

For a GATT example, the following depicts a GATT Server having two services (one Public, one Private), with a GATT
Client executing several GATT operations to read/write the data (characteristics) in those services.

<img src="https://microchip.wikidot.com/local--files/wireless:ble-gatt-overview/gatt-example.png"
width="80%"
height="80%"
alt=""
align=center />

#### Universally Unique Identifier (UUID)

A universally unique identifier (UUID) is a globally unique 128-bit (16-byte) number that is used to
identify Profiles, Services and Data Types in a Generic Attribute (GATT) Profile.

For efficiency, the Bluetooth® Low Energy (BLE) specification adds support for shortened 16-bit
UUIDs. These shortened formats can `only be used` with `Bluetooth SIG defined GATT profiles`.

All UUIDs in BLE are 128-bits (i.e. a 16-bit SIG-approved UUID is actually just part of a 128 bit
UUID. For example, the Client Configuration Descriptor UUID (2902) is actually
00002902-0000-1000-8000–00805f9b34fb).

Therefore, these shortened formats can only be used with UUIDs that are defined by the BLE
specification.

#### Generic Attribute Profile (GATT) Roles

Bluetooth Low Energy (BLE) `data communications` are implemented in the Generic Attribute Profile
(GATT) layer using the Attribute Protocol (ATT), a simple client/server `stateless` protocol.

The following GATT role pair is defined:
+ Server
<br> 1. Contains the resources (Data) to be monitored
<br> 2. Organized as an Attribute Database
<br> 3. Receives requests from a client and sends responses back
<br> 4. Typically associated with the `Link Layer Slave` and `GAP Peripheral device` roles

+ Client
<br> 1. Inquires about the presence and nature of the attributes on a server, Performs Service Discovery
<br> 2. Sends requests to a server and receives responses
<br> 3. Typically associated with the `Link Layer Master` and `GAP Central` device roles

For example, The following depicts a GATT Server having two services (one Public, one Private), with
a GATT Client executing several GATT operations to read/write the data (characteristics) in those
services.

<img src="https://microchip.wikidot.com/local--files/wireless:ble-gatt-roles/gatt-example-highlighted-roles.png"
width="80%"
height="80%"
alt=""
align=center />

#### GATT Attributes

todo

#### Attribute and Data Hierarchy
todo


