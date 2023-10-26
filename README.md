#asciidump

Command line tool which prints bytes from stdin or a list of files in ascii characters and well-known escape sequences

##examples

$IFS describes which characters the shell uses to determine argument boundaries 
> echo $IFS | asciidump
\s\t\n\0\n
