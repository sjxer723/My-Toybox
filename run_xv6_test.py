import re
import os
import argparse
import time

def run_xv6_test(outdir):
    os.system('cd xv6-labs-2021/ && make clean && make qemu >../{}'.format(outdir))

if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument('--test', default='array_test1', help='select one test among all testcases')
    parser.add_argument('--logdir', default='out/xv6.log')
    parser.add_argument('--outdir', default='out/xv6_metadata.txt')
    
    args = parser.parse_args()
    
    if not os.path.exists('./out'):
        os.mkdir('./out')
    if not os.path.exists('./test'):
        os.mkdir('./test')
    if not os.path.exists('./xv6-labs-2021/testcases/'):
        os.mkdir('./xv6-labs-2021/testcases/')
    if not os.path.exists('./testcases/{}.c'.format(args.test)):
        print("The test case {} is not exist".format(args.test))
        exit(0)
    os.system('cp testcases/{}.c ./xv6-labs-2021/user/test.c'.format(args.test))
    os.system('cp testcases/io.inc ./xv6-labs-2021/user/'.format(args.test))
    if os.fork() > 0: 
        time.sleep(15)
        os.system('killall qemu-system-riscv64')
        print("Close child process successfully!")
        with open(args.logdir) as f:
            content = f.read()
            f.close()
        with open(args.outdir, 'w') as updated_f:
            str = "Number of syscall: {}".format(len(re.findall(r': syscall [a-zA-Z]+ ->', content)))
            updated_f.writelines(str)
    else:
        run_xv6_test(args.logdir)
        