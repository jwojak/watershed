function [labelleded_image] = vincent_soille_watershed(input_image, connectivity)
%
%   [lablleded_image] = vincent_soille_watershed(input_image, connectivity)
%    image labelling using watershed algorithm of vincent & soille
%     "Watersheds in Digital Spaces: An Efficient Algorithm Based 
%      on Immersion Simulations."
%      IEEE Trans. on PAMI. 13 (1991) 583\u2013598 14.
%  and
%    "Roerdink, Jos BTM, and Arnold Meijster. "The watershed transform: 
%     Definitions, algorithms and parallelization strategies." 
%     Fundamenta informaticae 41.1, 2 (2000): 187-228.
%
% INPUT:
%  input_image: a quantified 2D image with integer pixel intensity
%
% OPTIONAL INPUT
%  connectivity: connectivity for neighborhood (default value 4, other 
%                 possible value 8)
%
% OUTPUT:
%  labelled_image: labelled resulting image (watershed label is 0)
%

if(nargin < 2)
    connectivity = 4;
end

if(connectivity ~= 4 && connectivity ~=8)
   ME = MException('vincent_soille_watershed:io_error', ...
       'connectivity must be equal to 4 or 8');
   throw(ME);
end

tmp = watershed_matlab(double(input_image'),connectivity);
labelleded_image = tmp';

end