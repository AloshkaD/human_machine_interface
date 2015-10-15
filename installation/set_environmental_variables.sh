# Build the directories
TEMP_HMI_PATH=$(pwd)
TEMP_OSG_FILE_PATH="$(echo $OSG_FILE_PATH | tr ':' '\n' | sed -n 1p):$TEMP_HMI_PATH/human_machine_interface/src/view/resources/osg_dataset"

# Removes previous version
sed -i '/HMI_PATH/d' ~/.bashrc
sed -i '/OSG_FILE_PATH/d' ~/.bashrc
sleep 1

# Write them in the .bashrc file
echo export HMI_PATH="$TEMP_HMI_PATH" >> ~/.bashrc
echo export OSG_FILE_PATH="$TEMP_OSG_FILE_PATH" >> ~/.bashrc
echo "Set HMI_PATH as $TEMP_HMI_PATH"
echo "Set OSG_FILE_PATH as $TEMP_OSG_FILE_PATH"