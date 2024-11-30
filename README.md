![imagem_2024-11-30_103728333](https://github.com/user-attachments/assets/c0d598cc-d82d-4ff1-9108-f8567543dde7)
# Prefetch-Secure-Cleaner
Prefetch cleaner to clean traces of this artifact.

1- First the application disables the Sysmain prefetch service

2- All files are truncated to zero bytes, after which they are overwritten with completely random data and after that they are renamed to random names and taken to the C:\Windows\Temp folder and finally deleted.

3- The application closes after successfully completing its function.

Making it extremely difficult to retrieve prefetch information, but all of this leaves traces in the USN journal that can be bypassed.
