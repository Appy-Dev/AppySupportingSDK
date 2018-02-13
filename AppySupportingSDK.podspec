Pod::Spec.new do |s|
s.name               = 'AppySupportingSDK'
s.version            = '1.0.0'
s.summary         = 'AppySDK is a framework for controlling objects in the houses.'
s.homepage        = 'https://github.com/Appy-Dev/AppySupportingSDK'
s.license         = 'MIT'
s.author               = 'AppySDK'
s.ios.deployment_target = '9.0'
s.source              = { :git => 'https://github.com/Appy-Dev/AppySupportingSDK.git', :tag => s.version }
s.ios.vendored_frameworks = 'AppySupportingSDK.framework'
end
