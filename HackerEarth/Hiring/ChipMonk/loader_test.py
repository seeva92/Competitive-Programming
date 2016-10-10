__author__ = 'anonymous'

import unittest
import json
from config_loader import ConfigLoader


class LoaderTest(unittest.TestCase):
    def test_settings_1(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps('26214400')
        actual = loader.get('common.basic_size_limit')
        print(expected)
        print(actual)
        self.assertEqual(expected, actual, "Matched")

    def test_settings_2(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps('52428800')
        actual = loader.get('common.student_size_limit')
        print(expected)
        print(actual)
        self.assertEqual(expected, actual, "Matched")

    def test_settings_3(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps('/srv/var/tmp/')
        actual = loader.get('common.path')
        print(expected)
        print(actual)
        self.assertEqual(expected, actual, "Matched")

    def test_settings_4(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps(None)
        actual = loader.get('common.settings')
        print(expected)
        print(actual)
        self.assertEqual(expected, actual, "Matched")

    def test_settings_5(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps('/srv/uploads/')
        actual = loader.get('ftp.path')
        print(expected)
        print(actual)
        self.assertEqual(expected, actual, "Matched")

    def test_settings_6(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = json.dumps('/etc/var/uploads')
        actual = loader.get('ftp.path')
        print(expected)
        print(actual)
        self.assertNotEqual(expected, actual, "Matched")

    def test_group_1(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = {}
        expected['common'] ={}
        expected['common']['basic_size_limit'] = '26214400'
        expected['common']['student_size_limit'] = '52428800'
        expected['common']['paid_users_size_limit'] = '2147483648'
        expected['common']['path'] = '/srv/var/tmp/'
        expected = json.dumps(expected['common'],indent=2,separators=(',',' == '))
        actual = loader.get('common')
        print(expected)
        print(actual)
        self.assertEqual(expected,actual,"Matched")

    def test_group_2(self):
        loader = ConfigLoader('config.ini', ['production', 'staging'])
        expected = {}
        expected['ftp'] ={}
        expected['ftp']['name'] = 'hello there, ftp uploading'
        expected['ftp']['path'] = '/srv/uploads/'
        expected['ftp']['enabled'] = 'no'
        expected = json.dumps(expected['ftp'],indent=2,separators=(',',' == '))
        actual = loader.get('ftp')
        print(expected)
        print(actual)
        self.assertEqual(expected,actual,"Matched")

    def test_group_3(self):
        loader = ConfigLoader('config.ini', ['production', 'staging','ubuntu'])
        expected = {}
        expected['ftp'] ={}
        expected['ftp']['name'] = 'hello there, ftp uploading'
        expected['ftp']['path'] = '/etc/var/uploads'
        expected['ftp']['enabled'] = 'no'
        expected = json.dumps(expected['ftp'],indent=2,separators=(',',' == '))
        actual = loader.get('ftp')
        print(expected)
        print(actual)
        self.assertEqual(expected,actual,"Matched")

    def test_group_4(self):
        loader = ConfigLoader('config.ini')
        expected = {}
        expected['ftp'] ={}
        expected['ftp']['name'] = 'hello there, ftp uploading'
        expected['ftp']['path'] = '/tmp/'
        expected['ftp']['enabled'] = 'no'
        expected = json.dumps(expected['ftp'],indent=2,separators=(',',' == '))
        actual = loader.get('ftp')
        print(expected)
        print(actual)
        self.assertEqual(expected,actual,"Matched")
if __name__ == '__main__':
    unittest.main()
