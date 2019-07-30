#ifndef SIOSIFMDEF_H
#define SIOSIFMDEF_H

// other constants
#define IFM_MAX_CHANNELS 4   // one device supports up to 4 channels
#define IFM_MAX_INTERNAL_SENSORS (4*6)
#define IFM_MAX_EXTERNAL_SENSORS  16
#define IFM_MAX_WL_SENSORS 15            // max. wireless temperature sensors
#define IFM_MAX_ENVIR_SENSORS  (IFM_MAX_EXTERNAL_SENSORS+IFM_MAX_INTERNAL_SENSORS+IFM_MAX_WL_SENSORS) // max. amount of environment sensors


#define IFM_I2C_MAXLEN   160 // for read/write requests with the IfmI2C... functions, max count of transfered data

#define IFM_MIN_TEMP                4   // �C
#define IFM_MAX_TEMP               50
#define IFM_MIN_AIRPRESSURE     70000   // Pa
#define IFM_MAX_AIRPRESSURE    120000
#define IFM_MIN_HUMIDITY            3   // %
#define IFM_MAX_HUMIDITY           99

#define IFM_SYNTHETIC_WAVELENGTH  632.83    // the DP-10 and IO-10 modules have the option to correct the values
                                            // for the environment influences
                                            // the corrected values seems to be derived from this synthetic wavelength

// -----------------------------------------------------Flags for settings of the parameter triggerMode in  the function :---------------------------
// ----------------------------------------------int IfmSetTrigger(int devNumber, unsigned int triggerMode);-----------------------------------------
// Functions for starting and stopping measurements
#define IFM_TRIGGER_OFF 		0


// Trigger-Input:
#define IFM_TRIGGER_START           0x0001   //start of measuring values after a valid (falling or rising) edge
#define IFM_TRIGGER_STARTSTOP_PROC  0x0002   //the StartStop-input of processed values
#define IFM_TRIGGER_STARTSTOP       0x0004   //the StartStop-input of raw values
#define IFM_TRIGGER_SET_TO_ZERO     0x8000   //the StartStop-input for set-to-zero

// Clock-Input
#define IFM_TRIGGER_CLOCK        0x0008      // clocks in unprocessed values from the counter/interpolator unit
                                             // It can be used to use an external sample rate or
                                             // to synchronize the sampling with external hardware (for example, incremental encoders)

//Event-Input
#define IFM_TRIGGER_EVENT        0x0010      // takes a processed value and sends it to the PC

// Edge definitions for Trigger
#define IFM_TRIGGER_CLOCK_RISING_EDGE         0x0100           //rising edge in the ext. clock input is validly
#define IFM_TRIGGER_STARTSTOP_RISING_EDGE     0x0200           //rising edge in the trigger  input is validly
#define IFM_TRIGGER_EVENT_RISING_EDGE         0x0400           //rising edge in the event input is validly

//Data rate of external clock or single value, for internal use only
#define IFM_OWR_FAST                0x1000              //fast data rate (OWR>200 Hz)
#define IFM_OWR_SLOW                0x2000              //slow data rate (OWR<=200Hz)
//-----------------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------------Flags for settings of the parameter filterFlags in the function------------------------------
//-------------------------------------------------------int IfmSetFilter(int devNumber, unsigned int filterFlags,int avg1, int avg2)------------------
// for experts only
#define IFM_FILTER_STAGE1	0x01                //Filter stage 1 (FIR) is on
#define IFM_FILTER_STAGE2	0x02                //Filter stage 2 (avg2) is on
#define IFM_FILTER_STAGE3	(IFM_FILTER_AVG9|IFM_FILTER_AVG6|IFM_FILTER_AVG5) //Filter stage 3 is on
#define IFM_FILTER_AVG9     0x04                // AVG9 in stage 3 is on
#define IFM_FILTER_AVG6     0x08                // AVG6 in stage 3 is on
#define IFM_FILTER_AVG5     0x10                // AVG5 in stage 3 is on
//-------------------------------------------------------------------------------------------------------------------------------------------------------

// -----------------------------------------------------Flags for settings of measurementFlags in  the function :-----------------------------------------
// ----------------------------------------------IfmSetMeasurement(int devNumber,unsigned int measurementFlags, int outputWordRate)-----------------------
#define IFM_MMASK_DEFAULT 0x0106  		//One channel, , SINX + COSX

// Field "MeasurementFlags", mask definition
#define IFM_MEAS_ONECHANNEL     0x0100              //Channel number 1 is on
#define IFM_MEAS_TWOCHANNEL     0x0300               //Channel number 1 and 2 are on
#define IFM_MEAS_THREECHANNEL   0x0700               //Channel number 1 to 3 are on
#define IFM_MEAS_FOURCHANNEL    0x0F00               //Channel number 1 to 4 are on

#define IFM_MEAS_TWOCHANNELS    IFM_MEAS_TWOCHANNEL
#define IFM_MEAS_THREECHANNELS  IFM_MEAS_THREECHANNEL
#define IFM_MEAS_FOURCHANNELS   IFM_MEAS_FOURCHANNEL

#define IFM_MEAS_CH1            0x0100
#define IFM_MEAS_CH2            0x0200
#define IFM_MEAS_CH3            0x0400
#define IFM_MEAS_CH4            0x0800


#define IFM_MEAS_USERMODE      0x0001               // Reserved
#define IFM_MEAS_LENGTH        0x0002               // Full length information
#define IFM_MEAS_SINCOS        0x0004               // SINX / COSX
#define IFM_MEAS_CIRCLE        0x0008               // Amplitude of the lissagous figure
#define IFM_MEAS_PATTERN       0x0010               // Test pattern
#define IFM_MEAS_CLOCKCOUNT    0x0020               // Internal clock counter; 50MHz timebase
#define IFM_MEAS_VAL_COUNTER   IFM_MEAS_CLOCKCOUNT  // for compatibility
#define IFM_MEAS_SAMPLECOUNT   0x0080               // Sample counter
#define IFM_MEAS_VAL_MASK      (0x003F|0x0080)      // Selection of measurement values is coded in these bits
#define IFM_MEAS_BEAMBREAK_OFF 0x0040               // BeamBreak should not be monitored

#define IFM_MEAS_FILTER_DEFAULT  0x0000             //The default filter is to use
#define IFM_MEAS_FILTER_OFF      0x1000             //No filtering
#define IFM_MEAS_FILTER_USER     0x2000             //The user filter is to use
#define IFM_MEAS_FILTER_MASK     0x3000             //Filter flags are coded in these bits

#define IFM_MEAS_RAWMODE         0x4000             //Mode for testing purpose, do not use
//---------------------------------------------------------------------------------------------------------------------------------------------------------

// the channel mask for
// IfmSetToZero, IfmAngleValue, IfmAngleAvailable

#define IFM_CHANNEL1                      0x01
#define IFM_CHANNEL2                      0x02
#define IFM_CHANNEL3                      0x04
#define IFM_CHANNEL4                      0x08

// special for IfmAngleValue
// return the angle in seconds instead of mrad
#define IFM_ANGLE_SEC                     0x80



// IfmSensorProperty

// Internal note:
// Constants for IfmSensorProperty are also used in the environmental
// firmware, changes must be commited to the firmware sources!

// Type of the Sensor
#define IFM_ENVIR_SENSOR_TEMP   		0x10
#define IFM_ENVIR_SENSOR_HUMIDITY 		0x20
#define IFM_ENVIR_SENSOR_AIRPRESSURE    	0x30			
#define IFM_ENVIR_SENSOR_TEMP_MATERIAL 		0x40
#define IFM_ENVIR_SENSOR_TEMP_AUX   		0x50

// which channels is the sensor assigned?
#define IFM_ENVIR_CHANNEL1                      0x01
#define IFM_ENVIR_CHANNEL2                      0x02
#define IFM_ENVIR_CHANNEL3                      0x04
#define IFM_ENVIR_CHANNEL4                      0x08

//Flag to mark the values for Edlen-corection
#define IFM_ENVIR_EDLEN                         0x80

//Sensor is extern, not port if interferometer unit
#define IFM_ENVIR_SENSOR_EXTERN                 0x0400

// channel and sensor type are coded in one byte
// the following masks allow better to distinguish
#define IFM_ENVIR_SENSORMASK 	0x0070    // in these bits the sensor type is coded (IFM_ENVIR_SENSOR_TEMP ...)
#define IFM_ENVIR_CHANNELMASK 	0x000F    // in these bits the assitiated channels are coded (IFM_ENVIR_CHANNEL1...)
#define IFM_ENVIR_VALID         0x0100    // the sensor value was at least one time measured
#define IFM_ENVIR_CURRENT       0x0200    // the sensor value was measured recently, the value is current or up-to-date

// -- End IfmSensorProperty

// IfmEnvirAuxValue
#define IFM_ENVIR_AUX_BATT   0   // Battery level (if any) in percent
#define IFM_ENVIR_AUX_SMETER 1   // receiving strength level (S-Meter) of wireless sensors
#define IFM_ENVIR_AUX_WLNUMBER 2 // Number of the Wireless module (1..16), 0 if no Wireless sensor
#define IFM_ENVIR_AUX_SERIAL 3   // Serial number of the sensor, 0 = not known to the system

//IfmSetOptions
#define IFM_OPTION_DEBUGFILES     0x0001  // param1==1 create debug files; param1==2 recreate debug files (delete old debug infos)
#define IFM_OPTION_POLLSELF       0x0002  // IfmPoll is called by the application, otherwise the DLL starts a thread which calls IfmPoll
#define IFM_OPTION_BLOCKONCLOSE   0x0003  // IfmCloseDevice blocks until the device is closed
#define IFM_OPTION_BOOTLOADER     0x0004  // enables special mode for transfer new firmware code
#define IFM_OPTION_BEAMBREAK      0x0005  // for the global IfmWasBeamBreak function exists two different beam break indicators which can be selected here
#define IFM_OPTION_ZEROPHASE      0x0006  // during set to zero the angle part of the interferometer value can be cleared or not
#define IFM_OPTION_ZEROONCONNECT  0x0007  // automatic zeroing on connect
#define IFM_OPTION_DEBUGLEVEL     0x0008  // debugLevel>=2 prints the IfmLenghtValue and similar calls in the ifmdll.dbg file which let the debug file grow


//IfmDeviceInfo
// the following information can be requested with IfmDeviceInfo
#define IFM_DEVINFO_SRATE               1   //current sampleRate (internal, before reduction by filters)
#define IFM_DEVINFO_OUTRATE             2   //output word rate, like set by IfmSetMeasurement or saved in the flash
                                            // this is the real output wird rate, which may be differ from the selected due to steps in possible sample rate
#define IFM_DEVINFO_FILTERFLAGS         3   //filter flags, like set by IfmSetFilter or saved in the flash
#define IFM_DEVINFO_MEASUREMENTFLAGS    4   //mesurement flags, like set by IfmSetMeasurement or saved in the flash
#define IFM_DEVINFO_TRIGGERMODE         5   //trigger mode, like set by IfmSetTrigger or or saved in the flash
#define IFM_DEVINFO_AVG1                6   //filter option for the average 1, like set by IfmSetFilter or saved in the flash
#define IFM_DEVINFO_AVG2                7   //filter option for the average 2, like set by IfmSetFilter or saved in the flash
#define IFM_DEVINFO_AVAILABLE           8   // infos available, if not wait until the DLL has get it from the device
#define IFM_DEVINFO_SERIALNUMBER        9   // return the (USB-) serial number of the card
#define IFM_DEVINFO_RESETSTATUS        10   // resets the given bits in the device status
#define IFM_DEVINFO_READY              11   // ready for IfmStart
#define IFM_DEVINFO_VERSIONSTRING      12   // Firmware-Version and compiling data
#define IFM_DEVINFO_FPGAVERSION        13   // Version of the programmable hardware (FPGA)
#define IFM_DEVINFO_OUTRATE_POINTER    14   // Pointer to a double value, containing the OWR in higher resolution
#define IFM_DEVINFO_LINKEDCHANNELS1    15   // wich channels are linked to calculate an angle
#define IFM_DEVINFO_LINKEDCHANNELS2    16   // there are two pairs of linked channels possible
#define IFM_DEVINFO_BASEDISTANCE1_POINTER  17 // base distance of the linkes channels
#define IFM_DEVINFO_BASEDISTANCE2_POINTER  18 // same for the second pair
#define IFM_DEVINFO_LAST_I2C_CARDADDR  19   // card address of the active or last I2C request
#define IFM_DEVINFO_LAST_I2C_MEMADDR   20   // memory address of the active or last I2C request
#define IFM_DEVINFO_SRATE_POINTER      21   // pointer to the current sample rate (double value)
#define IFM_DEVINFO_PSD_COUNT          22   // count of the available PSD-Sensors (lateral shift sensors)
#define IFM_DEVINFO_PSD_TYPE           23   // type of PSD implementation, see below
#define IFM_DEVINFO_ELLFIT_STATUS      24   // Heydemann-corr by Ellipse fitting: Status on or off
#define IFM_DEVINFO_ELLFIT_COSOFFS_POINTER 25   // Heydemann-corr by Ellipse fitting: pointer to double value of cosine offset
#define IFM_DEVINFO_ELLFIT_SINOFFS_POINTER 26   // Heydemann-corr by Ellipse fitting: pointer to double value of sine offset
#define IFM_DEVINFO_ELLFIT_PHI_POINTER     27   // Heydemann-corr by Ellipse fitting: pointer to double value of phase angle
#define IFM_DEVINFO_ELLFIT_AR_POINTER      28   // Heydemann-corr by Ellipse fitting: pointer to double value of amplitude ratio
#define IFM_DEVINFO_ELLFIT_AMPL_POINTER      29   // Heydemann-corr by Ellipse fitting: pointer to double value of amplitude ratio

#define IFM_DEVINFO_ENVIRCOUNTER      30  // counter of the environment measurement, use with sensor Number:
                                          // IFM_DEVINFO_ENVIRCOUNTER|(sensorNumber*256)
#define IFM_DEVINFO_DP10LSB           31  // the parallel output of the DP-10 can be shifted , this request returns the shift value
                                          // the LSB of the DP-10 is wavelength/pow(2,17-IfmDeviceInfo(devNo,IFM_DEVINFO_DP10LSB))
                                          // the values may be different for each channel, request (channel*256)|IFM_DEVINFO_DP10LSB

#define IFM_DEVINFO_DEVICESERIALNUMBER_POINTER 32  //return a pointer to a char[12] which contains the serial number of the electronic unit

#define IFM_DEVINFO_ENVVALUE           33  // return pointer of struct with raw environmental data, request (sensorNumber*256)|IFM_DEVINFO_ENVVALUE

#define IFM_DEVINFO_ELLFIT_UPDATE      34  // Update of the Heydemann-corr lookup table on/off
#define IFM_DEVINFO_ELLFIT_COUNTER     35  // Counts the samples since the last calculation Heydemann-corr lookup table on/off
#define IFM_DEVINFO_WL_ENVVALUE        36  // return pointer of struct with raw environmental data for wireless sensors,
                                           // request (sensorNumber*256)|IFM_DEVINFO_ENVVALUE; sensorNumer from 0..14


#define IFM_DEVINFO_CMDDELAY          100  // delay in ms between transmitted commands
#define IFM_DEVINFO_I2CTIMEOUT        101  // timeout in ms for IfmI2CRead and IfmI2CWrite


// Type of PSD implementation, returned with IFM_DEVINFO_PSD_TYPE

#define IFM_PSDTYPE_NONE    0   // no PSD available
#define IFM_PSDTYPE_CARD    1   // PSD based on PSD-04 card, slow rate approx 1-4 samples per second
#define IFM_PSDTYPE_ADU     2   // PSD based on special ADU card; fast data rate like interferometer values


// IfmHasDeviceProperty

#define IFM_PROPERTY_BLOCKMODE          1
#define IFM_PROPERTY_PSD                2



// types for IfmAuxValues

#define IFM_VALUETYPE_COS   1
#define IFM_VALUETYPE_ADC1  1
#define IFM_VALUETYPE_SIN   2
#define IFM_VALUETYPE_ADC2  2
#define IFM_VALUETYPE_NORM  3
#define IFM_VALUETYPE_TESTPATTERN 4
#define IFM_VALUETYPE_CLOCKCOUNT 5
#define IFM_VALUETYPE_COUNTER 5
#define IFM_VALUETYPE_SAMPLECOUNT 6
#define IFM_VALUETYPE_PSD_X 7   // lateral displacement via PSD in 10nm steps
#define IFM_VALUETYPE_PSD_Y 8
#define IFM_VALUETYPE_PSDRAW_X 9   // lateral displacement via PSD in 10nm steps
#define IFM_VALUETYPE_PSDRAW_Y 10
#define IFM_VALUETYPE_PSD_SUM 11  // energy on the PSD

// Parameter select for IfmSignalQuality(int devNumber,int channel, int select)
#define IFM_SIGNALQ_A1	      0x10                //Amplitude of the signal 1
#define IFM_SIGNALQ_O1	      0x20                //Offset of the signal 2
#define IFM_SIGNALQ_A2	      0x40                //Amplitude of the signal 2
#define IFM_SIGNALQ_O2	      0x80                //Offset of the signal 2
#define IFM_SIGNALQ_SUM       0x100               //Overall quality from 0..100%
#define IFM_SIGNALQ_FREQ      0x200               //Frequency of the reference mirror vibrator
#define IFM_SIGNALQ_STATE     0x400               //Status of the signal control card; for internal use


// IfmManualEnvironment
#define IFM_ENVIR_MANUAL_T  		0x0002       // the temperatur was set manually
#define IFM_ENVIR_MANUAL_H  		0x0004       // the humidity was set manually
#define IFM_ENVIR_MANUAL_P  		0x0008       // the air pressure was set manually
#define IFM_ENVIR_MANUAL_WVP        0x0010      // the water vapour pressure was set manually
#define IFM_ENVIR_MANUAL_CONV       0x0020      // the conversion coefficient was set manually
//#define IFM_ENVIR_MANUAL_WL  		0x0040
#define IFM_ENVIR_MANUAL_VWL        0x0080     // the vacuum wavelength of the laser was set manually



// IfmTemperatureFlags, IfmAirPressureFlags, IfmHumidityFlags
#define IFM_ENVIRFLAG_SENSORMASK       0x00FF      // in these bits the sensor number is coded, where the value was measured
#define IFM_ENVIRFLAG_MEASURED          0x0100      // the value was measured; otherwise it's a default value
#define IFM_ENVIRFLAG_CURRENT           0x0200      // the value was measured with the last data set
                                                    // (in a typical configuration it's not older than 4 secs)
#define IFM_ENVIRFLAG_MANUAL            0x0400      // value was given manually per IfmSet... function


//Bits in the measurement data flags field; for internal use only
#define IFM_MFLAGS_RESERVED1  0x01
#define IFM_MFLAGS_BEAMBREAK  0x02
#define IFM_MFLAGS_OVERFLOW   0x04
#define IFM_MFLAGS_MISCOUNT   0x80


// IfmStatus returns the following flags

//the lower 16 bit are channel dependend
#define IFM_STATUS_BEAMBREAK_QUADRANT    0x0001   // miscount detected: the interferometer counter has detected an invalid jump over more than one quadrants
#define IFM_STATUS_BEAMBREAK_LEVEL       0x0002   // the signal amplitude is lower than a given threashold so that miscounts are likely
#define IFM_STATUS_LASER_STABLE          0x0010   // the laser(s) is(are) stable (only in systems with stabilized lasers)
#define IFM_STATUS_LASER_WAS_UNSTABLE    0x0020   // since last IfmSetZero the laser was at least one time unstable

// the upper 16 bit are independend from the channel
#define IFM_STATUS_BUFFER_OVERFLOW_DEV   0x0100   // the FIFO in the interferometer had an overflow; data loss by to large samplerate has occured
#define IFM_STATUS_BUFFER_OVERFLOW_DLL   0x0200   // the measurement value buffer in the DLL had an overlow; data loss by infrequent call of IfmGetValue
#define IFM_STATUS_BLOCKMODE             0x0400   // the device is in blockmode
#define IFM_STATUS_TRACER_LOCK           0x0800   // Tracer locked
#define IFM_STATUS_BAD_REQUEST           0x8000   // the status request could not be answered, perhaps due to bad deviceNumber or invalid channel


//Device types for IfmDeviceType
#define IFM_TYPE_NONE  0
#define IFM_TYPE_DEMO  1
#define IFM_TYPE_RE10  2  // the usual type, siosifm.dll is made to support RE-10 card
#define IFM_TYPE_RE06  3
#define IFM_TYPE_RAW   4  // internal type, provides raw packet communication

//Interfaces for IfmDeviceInterface
#define IFM_INTERFACE_NONE   0
#define IFM_INTERFACE_DEMO   1
#define IFM_INTERFACE_RS232  2
#define IFM_INTERFACE_USB    3
#define IFM_INTERFACE_NET    4


// Error codes
#define IFM_ERROR_NONE        0
#define IFM_ERROR_DEVICE_INVALID        -1
#define IFM_ERROR_BAD_CHANNEL  -2
#define IFM_ERROR_BAD_DEVICETYPE -3
#define IFM_ERROR_DATALEN        -4
#define IFM_ERROR_BAD_DEVICE  IFM_ERROR_DEVICE_INVALID
#define IFM_ERROR_UNKNOWN     -6
#define IFM_ERROR_DEVICECOUNT_OVERFLOW 	-10
#define IFM_ERROR_BAD_REQUESTTYPE -11
#define IFM_ERROR_INVALID_USB_ID -12
#define IFM_ERROR_CREATE_HANDLE -13
#define IFM_ERROR_NOT_IMPLEMENTED -100
#define IFM_ERROR_I2C_INUSE      -15
#define IFM_ERROR_I2C_WRITE      -16
#define IFM_ERROR_I2C_TIMEOUT    -17
#define IFM_ERROR_OWR_TOOHIGHT   -18
#define IFM_ERROR_INFO_NOT_AVAILABLE -19
#define IFM_ERROR_BAD_SENSOR     -20
#define IFM_ERROR_I2C_READ       -21
#define IFM_ERROR_BAD_PARAMETER  -22
#define IFM_ERROR_SPI_ANSWER     -23

#endif // SIOSIFMDEF_H
