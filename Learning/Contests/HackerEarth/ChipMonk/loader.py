__author__ = 'anonymous'
from collections import defaultdict
import re
class Loader:

    # Initialises the Loader instance
    def __init__(self,path,override=None):
        self.path = path
        self.override = override
        self._config = {}
        self.__group_pattern = re.compile(r'^(\[[a-zA-Z_]+\])')
        self.__comment_pattern = re.compile(r'^(\s*)(;.*)')
        self.__setting_pattern = re.compile(r'^(([a-zA-Z_]+)((?!<[a-zA-Z]+>)|(<[a-zA-Z]+>))((\s*)=(\s*))(.*))$')
        self.__setting_overridden_pattern = re.compile(r'^([a-zA-Z]+)(<[a-zA-Z]+>)$')
        self.__string_pattern = re.compile(r'^([a-zA-Z/0-9,]+)')
        self.__string_dq_pattern = re.compile(r'^(".*")')
        print(self.path)
        print(self.override)
        self.__load()

    # Validate and loads the settings
    def __load(self):
        with open(self.path,mode='r') as file_reader:
            current_group = ''
            for line in file_reader:

                # Check if the line is empty and skip if so
                if not line:
                    continue

                line = self.__sanitize(line)

                # Skip the line if it is a valid comment
                if self.__isValidComment(line):
                    continue
                elif self.__isValidGroup(line):
                    # Slice the group name from the line and set it as the current group
                    current_group = self.__getValidMatch(self.__group_pattern,line)
                    current_group = current_group[1:len(current_group)-1]
                    self._config[current_group] = {}
                    self.__validateSlug(line[len(current_group)+2:].strip())
                elif current_group and self.__isValidSetting(line):
                    # Make the Key value pair left = right
                    key = line[0:line.find('=')].strip()
                    val = line[line.find('=')+1:].strip()

                    # Identify if the key is overridden
                    override = self.__getOverriddenSettingMatch(key)

                    # Flag set to True by default
                    # Whether to use the overridden value or not
                    flag = True
                    if override and len(override.groups())>1:
                        if self.override and override.groups()[1][1:-1] in self.override:
                            key = override.groups()[0]
                            flag = True
                        else:
                            flag = False

                    # Value empty
                    if not val:
                        self._config[current_group][key] = None
                        continue


                    # Valid string(Boolean,Number,Params)
                    if self.__isValidString(val):
                        res = self.__getValidMatch(self.__string_pattern,val)

                        # Assign array of params or valid string(including a boolean)
                        if ',' in res and flag:
                            self._config[current_group][key] = [i.strip() for i in res.split(',')]
                        elif flag:
                            self._config[current_group][key] = res

                        self.__validateSlug(val[len(res):].strip())

                    # Valid Double quoted string
                    elif self.__isValidQuotedString(val):
                        res = self.__getValidMatch(self.__string_dq_pattern,val)

                        if flag:
                            self._config[current_group][key] = res[1:len(res)-1]

                        self.__validateSlug(val[len(res):].strip())
                    else:
                        raise ValueError("Config file is not well-formed")
                else:
                    raise ValueError("Config file is not well-formed")

    # Sanitize the line
    def __sanitize(self,val):
        return val.strip()

    # Check if the line is a comment
    def __isValidComment(self,val):
        return True if self.__comment_pattern.match(val) else False

    # Check if the line is a group
    def __isValidGroup(self,val):
        return True if self.__group_pattern.match(val) else False

    # Check if the line is a valid setting
    def __isValidSetting(self,val):
        return True if self.__setting_pattern.match(val) else False

    # Check if the setting is overridden:
    def __getOverriddenSettingMatch(self,val):
        res = self.__setting_overridden_pattern.match(val)
        return res

    # Check if the value is String
    def __isValidString(self,val):
        return True if self.__string_pattern.match(val) else False

    # Check if the value is quoted-string
    def __isValidQuotedString(self,val):
        return True if self.__string_dq_pattern.match(val) else False

    # Check if the remaining portion is valid
    def __validateSlug(self,val):
        if len(val)>0 and val[0]!=';':
            raise ValueError("Config file is not well-formed")

    # Get Valid First match
    def __getValidMatch(self,pattern,val):
        return pattern.match(val).group()




