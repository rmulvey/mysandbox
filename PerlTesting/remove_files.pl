### Start a Perl solution (I'm running out of time with bash)
# quit unless we have the correct number of command-line args
$num_args = $#ARGV;
if ($num_args != 1) {
    print "This scipt is used to remove files over 90 days old."
        echo "Usage: $ARGV[0] [path];
    exit;
}
$folder = $ARGV[0];
opendir(DIR,$folder) || die "opendir $folder failed";
#TODO: Have to update this regular expression
@files = grep(!/^\.\.?$/,readdir(DIR));
closedir(DIR);

# delete all files in directory
foreach $f (@files)
{
      system("rm $folder/$f");
}
### /End Perl solution

=== end ===
​
2.
Write a crontab entry that would run this script every night at 2am. Assume the client CSVs are in a directory called /home/data/uploads on the server.

===== start (code here) ====
Note: “minute hour day month * command” and assumes script is put in /usr/bin

00 02 * * * /usr/bin/remove_files.sh /home/data/uploads
=== end 

