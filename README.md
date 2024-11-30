# Prefetch-Secure-Cleaner
Prefetch cleaner to clean traces of this artifact.

1- First the application disables the Sysmain prefetch service

2- All files are truncated to zero bytes, after which they are overwritten with completely random data and after that they are renamed to random names and taken to the C:\Windows\Temp folder and finally deleted.

3- The application closes after successfully completing its function.
